// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "ezored/core/ApplicationCore.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class EZRCoreApplicationCore;

namespace djinni_generated
{

class ApplicationCore
{
public:
    using CppType = std::shared_ptr<::ezored::core::ApplicationCore>;
    using CppOptType = std::shared_ptr<::ezored::core::ApplicationCore>;
    using ObjcType = ::EZRCoreApplicationCore *;

    using Boxed = ApplicationCore;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType &cpp);
    static ObjcType fromCpp(const CppType &cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

} // namespace djinni_generated
