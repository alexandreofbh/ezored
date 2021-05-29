from files.core import gluecode


def run(params):
    # djinni configurations
    djinni_file = "proj.djinni"

    # cpp configuration
    cpp_namespace = "ezored::systemservice"
    cpp_include_prefix = "ezored/systemservice/"
    cpp_out = "generated-src/cpp/{0}".format(cpp_include_prefix)

    # objc configuration
    objc_prefix = "EZRSystemService"
    objc_out = "generated-src/objc/{0}".format(cpp_include_prefix)
    objc_include_cpp_prefix = "{0}".format(cpp_include_prefix)
    objc_include_prefix = "{0}".format(cpp_include_prefix)

    # java configuration
    java_package = "com.ezored.systemservice"
    java_out = "generated-src/java/{0}".format(java_package.replace(".", "/"))
    java_parcelable = "true"

    # jni configuration
    jni_out = "generated-src/jni/{0}".format(java_package.replace(".", "/"))
    jni_class = "EZRSystemServiceFooBar"
    jni_file = "EZRSystemServiceFooBar"
    jni_include_cpp_prefix = "{0}".format(cpp_include_prefix)
    jni_include_prefix = "{0}/".format(java_package.replace(".", "/"))
    jni_generate_main = "false"

    # module data
    module_data = {
        "name": "app-system-service",
        "tool_params": [
            "--java-out",
            java_out,
            "--java-package",
            java_package,
            "--ident-java-field",
            "mFooBar",
            "--java-implement-android-os-parcelable",
            java_parcelable,
            "--cpp-out",
            cpp_out,
            "--cpp-namespace",
            cpp_namespace,
            "--cpp-include-prefix",
            cpp_include_prefix,
            "--ident-cpp-field",
            "fooBar",
            "--ident-cpp-method",
            "fooBar",
            "--ident-cpp-file",
            "FooBar",
            "--ident-cpp-local",
            "fooBar",
            "--ident-jni-class",
            jni_class,
            "--ident-jni-file",
            jni_file,
            "--jni-include-cpp-prefix",
            jni_include_cpp_prefix,
            "--jni-include-prefix",
            jni_include_prefix,
            "--jni-out",
            jni_out,
            "--jni-generate-main",
            jni_generate_main,
            "--objc-out",
            objc_out,
            "--objc-type-prefix",
            objc_prefix,
            "--objc-include-prefix",
            objc_include_prefix,
            "--objcpp-include-cpp-prefix",
            objc_include_cpp_prefix,
            "--objcpp-include-prefix",
            objc_include_prefix,
            "--objcpp-out",
            objc_out,
            "--yaml-out",
            "yaml",
            "--idl",
            djinni_file,
        ],
    }

    params["module_data"] = module_data

    gluecode.generate(params)
