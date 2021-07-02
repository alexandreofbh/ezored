// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "ezored/io/FileHelper.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class EZRFileHelper;

namespace djinni_generated
{

class FileHelper
{
public:
    using CppType = std::shared_ptr<::ezored::io::FileHelper>;
    using CppOptType = std::shared_ptr<::ezored::io::FileHelper>;
    using ObjcType = EZRFileHelper *;

    using Boxed = FileHelper;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType &cpp);
    static ObjcType fromCpp(const CppType &cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

} // namespace djinni_generated
