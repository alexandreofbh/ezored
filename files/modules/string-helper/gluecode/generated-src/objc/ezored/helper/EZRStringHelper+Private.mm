// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#import "djinni/objc/DJICppWrapperCache+Private.h"
#import "djinni/objc/DJIError.h"
#import "djinni/objc/DJIMarshal+Private.h"
#import "ezored/helper/EZRStringHelper+Private.h"
#import "ezored/helper/EZRStringHelper.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface EZRStringHelper ()

- (id)initWithCpp:(const std::shared_ptr<::ezored::helper::StringHelper> &)cppRef;

@end

@implementation EZRStringHelper
{
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::ezored::helper::StringHelper>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::ezored::helper::StringHelper> &)cppRef
{
    if (self = [super init])
    {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nonnull NSString *)trim:(nonnull NSString *)value
{
    try
    {
        auto objcpp_result_ = ::ezored::helper::StringHelper::trim(::djinni::String::toCpp(value));
        return ::djinni::String::fromCpp(objcpp_result_);
    }
    DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSString *)leftTrim:(nonnull NSString *)value
{
    try
    {
        auto objcpp_result_ = ::ezored::helper::StringHelper::leftTrim(::djinni::String::toCpp(value));
        return ::djinni::String::fromCpp(objcpp_result_);
    }
    DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSString *)rightTrim:(nonnull NSString *)value
{
    try
    {
        auto objcpp_result_ = ::ezored::helper::StringHelper::rightTrim(::djinni::String::toCpp(value));
        return ::djinni::String::fromCpp(objcpp_result_);
    }
    DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSString *)toLower:(nonnull NSString *)value
{
    try
    {
        auto objcpp_result_ = ::ezored::helper::StringHelper::toLower(::djinni::String::toCpp(value));
        return ::djinni::String::fromCpp(objcpp_result_);
    }
    DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSString *)toUpper:(nonnull NSString *)value
{
    try
    {
        auto objcpp_result_ = ::ezored::helper::StringHelper::toUpper(::djinni::String::toCpp(value));
        return ::djinni::String::fromCpp(objcpp_result_);
    }
    DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSArray<NSString *> *)split:(nonnull NSString *)text
                                   sep:(nonnull NSString *)sep
                             trimEmpty:(BOOL)trimEmpty
{
    try
    {
        auto objcpp_result_ = ::ezored::helper::StringHelper::split(::djinni::String::toCpp(text),
                                                                    ::djinni::String::toCpp(sep),
                                                                    ::djinni::Bool::toCpp(trimEmpty));
        return ::djinni::List<::djinni::String>::fromCpp(objcpp_result_);
    }
    DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated
{

auto StringHelper::toCpp(ObjcType objc) -> CppType
{
    if (!objc)
    {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto StringHelper::fromCppOpt(const CppOptType &cpp) -> ObjcType
{
    if (!cpp)
    {
        return nil;
    }
    return ::djinni::get_cpp_proxy<EZRStringHelper>(cpp);
}

} // namespace djinni_generated

@end
