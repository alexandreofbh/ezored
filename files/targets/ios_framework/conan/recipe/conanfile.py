from conans import ConanFile, CMake


class TargetConan(ConanFile):
    name = "ios_framework"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "ezored_name": "ANY",
        "ezored_version": "ANY",
        "ezored_arch": "ANY",
        "ezored_group": "ANY",
    }
    default_options = {
        "shared": False,
        "fPIC": True,
        "ezored_name": "ezored",
        "ezored_version": "ANY",
        "ezored_arch": "ANY",
        "ezored_group": "",
        "sqlite3:threadsafe": 1,
        "sqlite3:build_executable": False,
        "poco:enable_apacheconnector": False,
        "poco:enable_cppparser": False,
        "poco:enable_crypto": True,
        "poco:enable_data": False,
        "poco:enable_data_mysql": False,
        "poco:enable_data_postgresql": False,
        "poco:enable_data_sqlite": False,
        "poco:enable_data_odbc": False,
        "poco:enable_encodings": False,
        "poco:enable_json": True,
        "poco:enable_jwt": True,
        "poco:enable_mongodb": False,
        "poco:enable_net": True,
        "poco:enable_netssl": True,
        "poco:enable_pdf": False,
        "poco:enable_pagecompiler": False,
        "poco:enable_pagecompiler_file2page": False,
        "poco:enable_pocodoc": False,
        "poco:enable_redis": False,
        "poco:enable_sevenzip": False,
        "poco:enable_util": True,
        "poco:enable_xml": True,
        "poco:enable_zip": False,
    }
    exports_sources = "*"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.definitions["CMAKE_BUILD_TYPE"] = self.settings.build_type
        cmake.definitions["PROJECT_CONFIG_NAME"] = self.options.get_safe("ezored_name")
        cmake.definitions["PROJECT_CONFIG_VERSION"] = self.options.get_safe(
            "ezored_version"
        )
        cmake.definitions["PROJECT_CONFIG_ARCH"] = self.options.get_safe("ezored_arch")
        cmake.definitions["PROJECT_CONFIG_GROUP"] = self.options.get_safe(
            "ezored_group"
        )
        cmake.configure()
        cmake.build()

    def requirements(self):
        self.requires("sqlite3/3.34.0")
        self.requires("rapidjson/1.1.0")
        self.requires("openssl/1.1.1i")
        self.requires("sqlitecpp/2.5.0")

        # uncomment only if you want use C++ http client instead of native android http client
        # self.requires("poco/1.10.1")
