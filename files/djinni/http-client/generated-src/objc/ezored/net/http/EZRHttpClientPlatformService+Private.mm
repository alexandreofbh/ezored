// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#import "ezored/net/http/EZRHttpClientPlatformService+Private.h"
#import "ezored/net/http/EZRHttpClientPlatformService.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "ezored/net/http/EZRHttpRequest+Private.h"
#import "ezored/net/http/EZRHttpResponse+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface EZRHttpClientPlatformService ()

- (id)initWithCpp:(const std::shared_ptr<::ezored::net::http::HttpClientPlatformService>&)cppRef;

@end

@implementation EZRHttpClientPlatformService {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::ezored::net::http::HttpClientPlatformService>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::ezored::net::http::HttpClientPlatformService>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (nonnull EZRHttpResponse *)doRequest:(nonnull EZRHttpRequest *)request {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->doRequest(::djinni_generated::HttpRequest::toCpp(request));
        return ::djinni_generated::HttpResponse::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto HttpClientPlatformService::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto HttpClientPlatformService::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<EZRHttpClientPlatformService>(cpp);
}

}  // namespace djinni_generated

@end