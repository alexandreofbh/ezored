// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#pragma once

#include <functional>

namespace ezored { namespace enums {

enum class CustomerStatusEnum : int {
    ACTIVE,
    INACTIVE,
};

} }  // namespace ezored::enums

namespace std {

template <>
struct hash<::ezored::enums::CustomerStatusEnum> {
    size_t operator()(::ezored::enums::CustomerStatusEnum type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std