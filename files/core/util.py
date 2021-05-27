"""Module: Util"""

import platform

# -----------------------------------------------------------------------------
def filter_list(full_list, excludes):
    s = set(excludes)
    return (x for x in full_list if x not in s)


# -----------------------------------------------------------------------------
def readable_file_size(num, suffix="b"):
    """
    Readable file size
    :param num: Bytes value
    :type num: int
    :param suffix: Unit suffix (optionnal) default = b
    :type suffix: str
    :rtype: str
    """
    for unit in ["", "k", "M", "G", "T", "P", "E", "Z"]:
        if abs(num) < 1024.0:
            return "%3.1f %s%s" % (num, unit, suffix)

        num /= 1024.0

    return "%.1f%s%s" % (num, "Yi", suffix)


# -----------------------------------------------------------------------------
def list_has_key(args, key):
    """
    Check is args have of not a key
    :param args:
    :param key:
    :return bool
    """
    if not args or not key:
        return False

    if key in args:
        return True

    return False


# -----------------------------------------------------------------------------
def get_arg_value(key, args):
    for arg in args:
        if arg and arg.startswith("{0}=".format(key)):
            return arg[(len(key) + 1) :]


# -----------------------------------------------------------------------------
def is_windows_platform():
    return any(platform.win32_ver())


# -----------------------------------------------------------------------------
def is_macos_platform():
    return platform.system().lower().startswith("darwin")


# -----------------------------------------------------------------------------
def is_linux_platform():
    return platform.system().lower().startswith("linux")


# -----------------------------------------------------------------------------
def get_version(params, config):
    version = get_arg_value("--version", params["args"])

    if not version or len(version) == 0:
        proj_path = params["proj_path"]
        target_name = params["target_name"]
        target_config = config.run(proj_path, target_name, params)
        version = target_config["version"]

    return version
