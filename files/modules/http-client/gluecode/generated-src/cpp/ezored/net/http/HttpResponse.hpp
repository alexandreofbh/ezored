// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include "ezored/net/http/HttpHeader.hpp"
#include <cstdint>
#include <string>
#include <utility>
#include <vector>

namespace ezored
{
namespace net
{
namespace http
{

struct HttpResponse final
{
    int32_t code;
    std::string body;
    std::string url;
    std::vector<HttpHeader> headers;

    HttpResponse(int32_t code_,
                 std::string body_,
                 std::string url_,
                 std::vector<HttpHeader> headers_)
        : code(std::move(code_)), body(std::move(body_)), url(std::move(url_)), headers(std::move(headers_))
    {
    }
};

} // namespace http
} // namespace net
} // namespace ezored
