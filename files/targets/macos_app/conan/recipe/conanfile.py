from conans import ConanFile, CMake


class TargetConan(ConanFile):
    name = "macos_app"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "ezored_name": "ANY",
        "ezored_arch": "ANY",
    }
    default_options = {
        "shared": False,
        "fPIC": True,
        "ezored_name": "ezored",
        "ezored_arch": "ANY",
        "sqlite3:threadsafe": 1,
        "sqlite3:build_executable": False,
        "boost:without_fiber": True,
        "boost:without_nowide": True,
        "boost:without_json": True,
        "boost:without_boost_locale": True,
        "boost:without_stacktrace_addr2line": True,
    }
    exports_sources = "*"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.definitions["CMAKE_BUILD_TYPE"] = self.settings.build_type
        cmake.definitions["PROJECT_CONFIG_NAME"] = self.options.get_safe("ezored_name")
        cmake.definitions["PROJECT_CONFIG_ARCH"] = self.options.get_safe("ezored_arch")
        cmake.definitions["CMAKE_OSX_DEPLOYMENT_TARGET"] = self.settings.get_safe(
            "os.version"
        )
        cmake.configure()
        cmake.build()

    def requirements(self):
        self.requires("sqlite3/3.34.0")
        self.requires("rapidjson/1.1.0")
        self.requires("openssl/1.1.1i")
        self.requires("sqlitecpp/2.5.0")
        self.requires("cpprestsdk/2.10.17")
        self.requires("boost/1.75.0")
