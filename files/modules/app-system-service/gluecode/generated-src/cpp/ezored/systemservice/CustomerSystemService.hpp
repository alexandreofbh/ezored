// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

#pragma once

#include <string>

namespace ezored
{
namespace systemservice
{

struct CustomerSystemServiceLoginData;

class CustomerSystemService
{
public:
    virtual ~CustomerSystemService() {}

    static CustomerSystemServiceLoginData login(const std::string &username, const std::string &password);
};

} // namespace systemservice
} // namespace ezored
