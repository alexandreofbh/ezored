"""Module: AWS"""

import os
import sys
import threading

from files.core import const
from files.core import file
from files.core import log
from files.core import net
from files.core import pack


# -----------------------------------------------------------------------------
def download(
    proj_path, version, dist_file_path, dist_file_name, dist_folder, aws_s3_url
):
    # version
    if not version or len(version) == 0:
        log.error("You need define version name (parameter: --version)")

    log.info("Version defined: {0}".format(version))

    # remove file
    log.info("Removing old file...")
    file.remove_file(dist_file_path)

    # download file
    log.info("Downloading {0} file...".format(dist_file_name))

    file_url = "{0}/{1}/{2}".format(aws_s3_url, version, dist_file_name)

    try:
        file.create_dir(os.path.dirname(dist_file_path))
        net.download(file_url, dist_file_path)
    except Exception as e:
        log.error("Error when download file {0}: {1}".format(file_url, e))

    # remove old files and unpack current file
    log.info("Removing old folder...")

    file.create_dir(os.path.join(proj_path, const.DIR_NAME_DIST))
    file.remove_dir(os.path.join(proj_path, const.DIR_NAME_DIST, dist_folder))

    log.info("Unpacking downloaded file...")

    pack.unpack(
        dist_file_path, os.path.join(proj_path, const.DIR_NAME_DIST, dist_folder)
    )

    log.ok("")


# -----------------------------------------------------------------------------
def upload(
    proj_path,
    version,
    force,
    dist_file_path,
    dist_file_name,
    dist_folder,
    aws_key_id,
    aws_secret_key,
    aws_bucket_name,
    aws_bucket_path,
):
    import boto3

    # version
    if not version or len(version) == 0:
        log.error("You need define version name (parameter: --version)")

    log.info("Version defined: {0}".format(version))

    # prepare to upload
    if not os.path.isfile(dist_file_path):
        log.error("Distribution file not exists: {0}".format(dist_file_path))

    # prepare aws sdk
    log.info("Initializing AWS bucket and SDK...")

    if not aws_key_id or not aws_secret_key:
        log.fail("Your AWS credentials are invalid")

    s3_client = boto3.client(
        service_name="s3",
        aws_secret_access_key=aws_secret_key,
        aws_access_key_id=aws_key_id,
    )

    # checking for existing version
    log.info("Checking if version exists...")

    object_name = "{0}/{1}/{2}".format(
        aws_bucket_path,
        version,
        dist_file_name,
    )

    has_version = s3_key_exists(s3_client, aws_bucket_name, object_name)

    if has_version:
        if force:
            log.info("The version {0} already exists, removing...".format(version))

            s3_prefix_delete(
                s3_client,
                aws_bucket_name,
                object_name,
                aws_secret_key,
                aws_key_id,
            )
        else:
            log.error("The version {0} already exists".format(version))

    # upload
    log.info(
        'Uploading file "{0}" to S3 bucket "{1}"...'.format(
            dist_file_path, aws_bucket_name
        )
    )

    s3_client.upload_file(
        dist_file_path,
        aws_bucket_name,
        object_name,
        ExtraArgs={"ACL": "public-read"},
        Callback=ProgressPercentage(dist_file_path),
    )

    log.normal("")
    log.ok("")


# -----------------------------------------------------------------------------
def s3_key_exists(s3, bucket, key):
    from botocore.exceptions import ClientError

    try:
        s3.head_object(Bucket=bucket, Key=key)
    except ClientError as e:
        error_code = int(e.response["Error"]["Code"])

        if error_code >= 400 and error_code <= 499:
            return False

    return True


# -----------------------------------------------------------------------------
def s3_prefix_delete(s3, bucket, key, aws_secret_access_key, aws_access_key_id):
    import boto3
    from botocore.exceptions import ClientError

    try:
        s3_resource = boto3.resource(
            "s3",
            aws_secret_access_key=aws_secret_access_key,
            aws_access_key_id=aws_access_key_id,
        )

        s3_resource.Object(bucket, key).delete()
    except Exception as e:
        log.error("Failed to delete key {0} from AWS S3: {1}".format(key, e))

    return True


# -----------------------------------------------------------------------------
def s3_create_dir(s3, bucket, key, aws_secret_access_key, aws_access_key_id):
    import boto3
    from botocore.exceptions import ClientError

    try:
        s3.put_object(Bucket=bucket, Key=(key + "/"))
    except Exception as e:
        log.error("Failed to create dir {0} on AWS S3: {1}".format(key, e))

    return True


# -----------------------------------------------------------------------------
def s3_dir_exists(s3, bucket, key):
    from botocore.exceptions import ClientError

    try:
        s3.head_object(Bucket=bucket, Key=key + "/")
    except ClientError as e:
        error_code = int(e.response["Error"]["Code"])

        if error_code >= 400 and error_code <= 499:
            return False

    return True


# -----------------------------------------------------------------------------
def s3_dir_delete(s3, bucket, key, aws_secret_access_key, aws_access_key_id):
    import boto3
    from botocore.exceptions import ClientError

    try:
        s3_resource = boto3.resource(
            "s3",
            aws_secret_access_key=aws_secret_access_key,
            aws_access_key_id=aws_access_key_id,
        )

        s3_bucket = s3_resource.Bucket(bucket)

        s3_bucket.objects.filter(Prefix=key + "/").delete()
    except Exception as e:
        log.error("Failed to delete key {0} from AWS S3: {1}".format(key, e))

    return True


# -----------------------------------------------------------------------------
class ProgressPercentage(object):
    def __init__(self, filename):
        self._filename = filename
        self._size = float(os.path.getsize(filename))
        self._seen_so_far = 0
        self._lock = threading.Lock()

    def __call__(self, bytes_amount):
        with self._lock:
            self._seen_so_far += bytes_amount
            percentage = (self._seen_so_far / self._size) * 100
            sys.stdout.write(
                "\r%s  %s / %d  (%.2f%%)"
                % (
                    os.path.basename(self._filename),
                    self._seen_so_far,
                    self._size,
                    percentage,
                )
            )
            sys.stdout.flush()
