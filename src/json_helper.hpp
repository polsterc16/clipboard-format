#pragma once

#include <nlohmann/json.hpp>

namespace json_helper{
    nlohmann::json default_json();
    nlohmann::json test_json();
    int test_int();
}