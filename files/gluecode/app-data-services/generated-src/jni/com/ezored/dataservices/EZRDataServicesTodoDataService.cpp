// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#include "com/ezored/dataservices/EZRDataServicesTodoDataService.hpp"  // my header
#include "Marshal.hpp"
#include "com/ezored/domain/EZRDomainTodo.hpp"

namespace djinni_generated {

EZRDataServicesTodoDataService::EZRDataServicesTodoDataService() : ::djinni::JniInterface<::ezored::dataservices::TodoDataService, EZRDataServicesTodoDataService>("com/ezored/dataservices/TodoDataService$CppProxy") {}

EZRDataServicesTodoDataService::~EZRDataServicesTodoDataService() = default;


CJNIEXPORT void JNICALL Java_com_ezored_dataservices_TodoDataService_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ezored::dataservices::TodoDataService>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_ezored_dataservices_TodoDataService_00024CppProxy_truncate(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::ezored::dataservices::TodoDataService::truncate();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT ::djinni_generated::EZRDomainTodo::JniType JNICALL Java_com_ezored_dataservices_TodoDataService_00024CppProxy_findById(JNIEnv* jniEnv, jobject /*this*/, jlong j_id)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ezored::dataservices::TodoDataService::findById(::djinni::I64::toCpp(jniEnv, j_id));
        return ::djinni::release(::djinni_generated::EZRDomainTodo::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_ezored_dataservices_TodoDataService_00024CppProxy_findAllOrderByCreatedAtDesc(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ezored::dataservices::TodoDataService::findAllOrderByCreatedAtDesc();
        return ::djinni::release(::djinni::List<::djinni_generated::EZRDomainTodo>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_ezored_dataservices_TodoDataService_00024CppProxy_findByTitle(JNIEnv* jniEnv, jobject /*this*/, jstring j_title)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ezored::dataservices::TodoDataService::findByTitle(::djinni::String::toCpp(jniEnv, j_title));
        return ::djinni::release(::djinni::List<::djinni_generated::EZRDomainTodo>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_ezored_dataservices_TodoDataService_00024CppProxy_removeById(JNIEnv* jniEnv, jobject /*this*/, jlong j_id)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::ezored::dataservices::TodoDataService::removeById(::djinni::I64::toCpp(jniEnv, j_id));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_ezored_dataservices_TodoDataService_00024CppProxy_update(JNIEnv* jniEnv, jobject /*this*/, jlong j_id, ::djinni_generated::EZRDomainTodo::JniType j_todo)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::ezored::dataservices::TodoDataService::update(::djinni::I64::toCpp(jniEnv, j_id),
                                                        ::djinni_generated::EZRDomainTodo::toCpp(jniEnv, j_todo));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jlong JNICALL Java_com_ezored_dataservices_TodoDataService_00024CppProxy_insert(JNIEnv* jniEnv, jobject /*this*/, ::djinni_generated::EZRDomainTodo::JniType j_todo)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ezored::dataservices::TodoDataService::insert(::djinni_generated::EZRDomainTodo::toCpp(jniEnv, j_todo));
        return ::djinni::release(::djinni::I64::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jlong JNICALL Java_com_ezored_dataservices_TodoDataService_00024CppProxy_add(JNIEnv* jniEnv, jobject /*this*/, ::djinni_generated::EZRDomainTodo::JniType j_todo)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ezored::dataservices::TodoDataService::add(::djinni_generated::EZRDomainTodo::toCpp(jniEnv, j_todo));
        return ::djinni::release(::djinni::I64::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_ezored_dataservices_TodoDataService_00024CppProxy_setDoneById(JNIEnv* jniEnv, jobject /*this*/, jlong j_id, jboolean j_done)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::ezored::dataservices::TodoDataService::setDoneById(::djinni::I64::toCpp(jniEnv, j_id),
                                                             ::djinni::Bool::toCpp(jniEnv, j_done));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
