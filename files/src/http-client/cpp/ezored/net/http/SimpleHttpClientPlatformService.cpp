#include "SimpleHttpClientPlatformService.hpp"

#include "ezored/net/http/HttpHeader.hpp"
#include "ezored/net/http/HttpMethod.hpp"
#include "ezored/net/http/HttpRequest.hpp"
#include "ezored/net/http/HttpRequestParam.hpp"
#include "ezored/net/http/HttpResponse.hpp"

#include "ezored/helpers/StringHelper.hpp"

#include "cpprest/filestream.h"
#include "cpprest/http_client.h"

#include <iostream>
#include <map>
#include <sstream>
#include <string>

namespace ezored
{
namespace net
{
namespace http
{

using namespace ezored::net::http;
using namespace ezored::helpers;

HttpResponse SimpleHttpClientPlatformService::doRequest(const HttpRequest &request)
{
    auto response = HttpResponse{0, "", "", {}};

    try
    {
        // prepare session
        web::http::client::http_client httpClient(request.url.c_str());

        // send request
        web::http::http_request httpRequest(getMethodFromRequest(request));

        // set headers here
        for (auto &header : request.headers)
        {
            httpRequest.headers().add(header.name, header.value);
        }

        // set the request body
        std::string body;

        if (request.params.size() > 0)
        {
            for (auto &param : request.params)
            {
                if (body.length() > 0)
                {
                    body = body + "&" + param.name + "=" + param.value;
                }
                else
                {
                    body = param.name + "=" + param.value;
                }
            }
        }
        else
        {
            body = request.body;
        }

        httpRequest.headers().set_content_length(static_cast<std::streamsize>(body.length()));
        httpRequest.set_body(body);

        // get response
        auto httpResponse = httpClient.request(httpRequest)
                                .then([](web::http::http_response response) {
                                    return response;
                                })
                                .get();

        response.body = httpResponse.extract_string().get();
        response.code = httpResponse.status_code();
        response.url = request.url;

        // get headers
        for (auto &header : httpResponse.headers())
        {
            response.headers.push_back(HttpHeader(header.first, header.second));
        }
    }
    catch (std::exception &ex)
    {
        response.body = ex.what();
    }

    return response;
}

std::string SimpleHttpClientPlatformService::getMethodFromRequest(const HttpRequest &request)
{
    switch (request.method)
    {
    case HttpMethod::METHOD_GET:
        return web::http::methods::GET;
        break;
    case HttpMethod::METHOD_POST:
        return web::http::methods::POST;
        break;
    case HttpMethod::METHOD_HEAD:
        return web::http::methods::HEAD;
        break;
    case HttpMethod::METHOD_PUT:
        return web::http::methods::PUT;
        break;
    case HttpMethod::METHOD_DELETE:
        return web::http::methods::DEL;
        break;
    case HttpMethod::METHOD_PATCH:
        return web::http::methods::PATCH;
        break;
    case HttpMethod::METHOD_CONNECT:
        return web::http::methods::CONNECT;
        break;
    case HttpMethod::METHOD_OPTIONS:
        return web::http::methods::OPTIONS;
        break;
    case HttpMethod::METHOD_TRACE:
        return web::http::methods::TRCE;
        break;
    }

    return "";
}

} // namespace http
} // namespace net
} // namespace ezored
