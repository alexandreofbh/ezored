// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include <cstdint>
#include <string>
#include <utility>

namespace ezored
{
namespace net
{
namespace http
{

struct HttpServerConfig final
{
    int32_t port;
    std::string staticPath;

    HttpServerConfig(int32_t port_,
                     std::string staticPath_)
        : port(std::move(port_)), staticPath(std::move(staticPath_))
    {
    }

    HttpServerConfig()
        : port(), staticPath()
    {
    }
};

} // namespace http
} // namespace net
} // namespace ezored
