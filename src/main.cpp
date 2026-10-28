#include <clip/clip.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <format>
#include <nlohmann/json.hpp>
#include "json_helper.hpp"

// using nlohmann::json;


int main(int, char **) {
  namespace JH = json_helper;
  using json = nlohmann::json;

  // std::cout << "nlohmann: " << type(nlohmann) << std::endl;
  // std::cout << "nlohmann::json: " << type(nlohmann::json()) << std::endl;
  std::cout << JH::test_int() << std::endl;

  std::cout << JH::test_json() << std::endl;

  return EXIT_SUCCESS;
  // namespace Active = nlohmann::json;

  // std::cout << "Hello, from clipboard-format!" << std::endl;

  // Active::json j = {{"a",1},{"b",2}};
  // std::cout << std::setw(4) << j << std::endl;
  // return EXIT_SUCCESS;

  int wdt;
  size_t p;

  if (clip::has(clip::text_format())) {
    std::string value;
    clip::get_text(value);

    //std::cout << "Clipboard content is " << std::endl;
    //std::cout << "[" << value << "]" << std::endl;
    //std::cout << std::endl;

    wdt = 100;
    while (wdt > 0){
      wdt--;
      p = value.find("\n");
      if (p == std::string::npos) { break; }
      value = value.replace(p, 1, " ");
    }
    wdt = 100;
    while (wdt > 0){
      wdt--;
      p = value.find("\r");
      if (p == std::string::npos) { break; }
      value = value.replace(p, 1, " ");
    }
    wdt = 100;
    while (wdt > 0){
      wdt--;
      p = value.find("\t");
      if (p == std::string::npos) {
        //std::cout << "not found. "<< wdt << std::endl;
        break;
      }
      //std::cout << "found at "<< p << " "<< wdt << std::endl;
      value = value.replace(p, 1, " ");
    }
    wdt = 100;
    while (wdt > 0){
      wdt--;
      p = value.find("/");
      if (p == std::string::npos) { break; }
      value = value.replace(p, 1, " ");
    }
    wdt = 100;
    while (wdt > 0){
      wdt--;
      p = value.find(":");
      if (p == std::string::npos) { break; }
      value = value.replace(p, 1, ".");
    }
    wdt = 100;
    while (wdt > 0){
      wdt--;
      p = value.find("  ");
      if (p == std::string::npos) { break; }
      value = value.replace(p, 2, " ");
    }

    size_t start = value.find_first_not_of(" \t\r\n");
    size_t end = value.find_last_not_of(" \t\r\n");
    
    if (start == std::string::npos) {
      return EXIT_SUCCESS; // String is all whitespace
    }
    
    value = value.substr(start, end - start + 1);

    std::cout << value << std::endl;
    clip::set_text(value);
  }

  return EXIT_SUCCESS;
}
