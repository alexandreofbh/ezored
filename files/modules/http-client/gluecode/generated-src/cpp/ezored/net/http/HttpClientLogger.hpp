// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

namespace ezored
{
namespace net
{
namespace http
{

struct HttpRequest;
struct HttpResponse;

class HttpClientLogger
{
public:
    virtual ~HttpClientLogger() {}

    virtual void onRequest(const HttpRequest &request) = 0;

    virtual void onResponse(const HttpRequest &request, const HttpResponse &response) = 0;
};

} // namespace http
} // namespace net
} // namespace ezored
