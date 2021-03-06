def run(proj_path, target_name, params):
    return {
        "project_name": "ezored",
        "version": "1.0.0",
        "build_types": ["Debug", "Release"],
        "archs": [
            {
                "arch": "armv7",
                "conan_arch": "armv7",
                "conan_profile": "ezored_ios_framework_profile",
                "min_version": "9.0",
                "supported_platform": "iPhoneOS",
                "enable_bitcode": True,
                "group": "ios",
            },
            {
                "arch": "armv7s",
                "conan_arch": "armv7s",
                "conan_profile": "ezored_ios_framework_profile",
                "min_version": "9.0",
                "supported_platform": "iPhoneOS",
                "enable_bitcode": True,
                "group": "ios",
            },
            {
                "arch": "arm64",
                "conan_arch": "armv8",
                "conan_profile": "ezored_ios_framework_profile",
                "min_version": "9.0",
                "supported_platform": "iPhoneOS",
                "enable_bitcode": True,
                "group": "ios",
            },
            {
                "arch": "arm64e",
                "conan_arch": "armv8.3",
                "conan_profile": "ezored_ios_framework_profile",
                "min_version": "9.0",
                "supported_platform": "iPhoneOS",
                "enable_bitcode": True,
                "group": "ios",
            },
            {
                "arch": "x86_64",
                "conan_arch": "x86_64",
                "conan_profile": "ezored_ios_framework_profile",
                "min_version": "9.0",
                "supported_platform": "iPhoneSimulator",
                "enable_bitcode": False,
                "group": "ios_simulator",
            },
        ],
        "install_headers": [
            {
                "type": "dir",
                "path": "files/gluecode/app-domain/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/gluecode/app-enums/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/gluecode/app-core/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/gluecode/app-data-services/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/gluecode/app-system-services/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/gluecode/app-helpers/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/gluecode/datetime/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/gluecode/file-helper/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/gluecode/http-client/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/gluecode/shared-data/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/gluecode/logger/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/gluecode/string-helper/generated-src/objc",
            },
            {
                "type": "dir",
                "path": "files/src/file-helper/objc",
            },
            {
                "type": "dir",
                "path": "files/src/logger/objc",
            },
            {
                "type": "dir",
                "path": "files/src/shared-data/objc",
            },
            {
                "type": "dir",
                "path": "files/src/http-client/objc",
            },
        ],
        "umbrella_header": "Ezored.h",
    }
