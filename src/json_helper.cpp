#include "json_helper.hpp"

namespace json_helper{
    using json = nlohmann::json;

    // https://json.nlohmann.me/api/basic_json/#examples
    json default_json(){
    // create a JSON object
        json j =
        {
            {"\r", " "},
            {"\n", " "},
            {"\t", " "},
            {"/", " "},
            {":", "."},
            {"  ", " "},
            {"..", "."}
        };
        return j;
    }

    json test_json(){
    // create a JSON object
        json j =
        {
            {"a", 1},
            {"b", "def"},
            {"c", 3}
        };
        return j;
    }
    int test_int(){return 123123123;}
}