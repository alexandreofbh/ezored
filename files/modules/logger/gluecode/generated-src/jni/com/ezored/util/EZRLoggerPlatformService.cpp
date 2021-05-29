// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#include "com/ezored/util/EZRLoggerPlatformService.hpp" // my header
#include "djinni/jni/Marshal.hpp"

namespace djinni_generated
{

EZRLoggerPlatformService::EZRLoggerPlatformService() : ::djinni::JniInterface<::ezored::util::LoggerPlatformService, EZRLoggerPlatformService>() {}

EZRLoggerPlatformService::~EZRLoggerPlatformService() = default;

EZRLoggerPlatformService::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) {}

EZRLoggerPlatformService::JavaProxy::~JavaProxy() = default;

void EZRLoggerPlatformService::JavaProxy::v(const std::string &c_message)
{
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto &data = ::djinni::JniClass<::djinni_generated::EZRLoggerPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_v,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_message)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void EZRLoggerPlatformService::JavaProxy::d(const std::string &c_message)
{
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto &data = ::djinni::JniClass<::djinni_generated::EZRLoggerPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_d,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_message)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void EZRLoggerPlatformService::JavaProxy::i(const std::string &c_message)
{
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto &data = ::djinni::JniClass<::djinni_generated::EZRLoggerPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_i,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_message)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void EZRLoggerPlatformService::JavaProxy::w(const std::string &c_message)
{
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto &data = ::djinni::JniClass<::djinni_generated::EZRLoggerPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_w,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_message)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void EZRLoggerPlatformService::JavaProxy::e(const std::string &c_message)
{
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto &data = ::djinni::JniClass<::djinni_generated::EZRLoggerPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_e,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_message)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void EZRLoggerPlatformService::JavaProxy::setGroup(const std::string &c_group)
{
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto &data = ::djinni::JniClass<::djinni_generated::EZRLoggerPlatformService>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_setGroup,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_group)));
    ::djinni::jniExceptionCheck(jniEnv);
}

} // namespace djinni_generated
