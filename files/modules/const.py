"""Constants"""

DIR_NAME_EZORED = "ezored"
DIR_NAME_EZORED_CMD = "cmd"
DIR_NAME_FILES = "files"
DIR_NAME_GLUECODE = "gluecode"
DIR_NAME_HOME_CONAN = ".conan"
DIR_NAME_HOME_CONAN_PROFILES = "profiles"
DIR_NAME_BUILD = "build"
DIR_NAME_BUILD_TARGETS = "targets"
DIR_NAME_BUILD_TARGET = "target"
DIR_NAME_DIST = "dist"
DIR_NAME_BUILD_CONAN = "conan"
DIR_NAME_FILES_CMAKE = "cmake"
DIR_NAME_FILES_CONFIG = "config"
DIR_NAME_FILES_TARGETS = "targets"
DIR_NAME_FILES_TARGET_CMAKE = "cmake"
DIR_NAME_FILES_TARGET_CONAN = "conan"
DIR_NAME_FILES_TARGET_CONAN_PROFILE = "profile"
DIR_NAME_FILES_TARGET_CONAN_RECIPE = "recipe"
DIR_NAME_FILES_TARGET_VERBS = "verbs"
DIR_NAME_FILES_TARGET_SUPPORT = "support"
DIR_NAME_FILES_COMMANDS = "commands"
DIR_NAME_FILES_SRC = "src"
DIR_NAME_PROJECTS = "projects"

FILE_NAME_FILES_TARGET_CONAN_RECIPE_CONANFILE_TXT = "conanfile.txt"
FILE_NAME_FILES_TARGET_CONAN_RECIPE_CONANFILE_PY = "conanfile.py"
FILE_NAME_DIST_PACKED = "dist.tar.gz"

URL_DIST_FILE_PACKED = "http://public.ezored.com/ezored/prebuilt/dist.tar.gz"

AWS_S3_KEY_ENV = "EZORED_AWS_KEY"
AWS_S3_SECRET_ENV = "EZORED_AWS_SECRET"
AWS_S3_BUCKET_NAME = "EZORED_AWS_SECRET"
AWS_S3_BUCKET_PATH = "sdk"
AWS_S3_URL = "https://s3.amazonaws.com/{0}/sdk".format(AWS_S3_BUCKET_NAME)

TARGET_VERBS_INTERNAL = ["config"]