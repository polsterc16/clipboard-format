#include <clip/clip.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <format>

int main(int, char **) {
  
  //std::cout << "Hello, from clipboard-format!" << std::endl;

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
      p = value.find("  ");
      if (p == std::string::npos) { break; }
      value = value.replace(p, 2, " ");
    }
    wdt = 100;
    while (wdt > 0){
      wdt--;
      p = value.find(":");
      if (p == std::string::npos) { break; }
      value = value.replace(p, 1, ".");
    }

    size_t start = value.find_first_not_of(" \t\r\n");
    size_t end = value.find_last_not_of(" \t\r\n");
    
    if (start == std::string::npos) {
      std::cout << start;
      return 0; // String is all whitespace
    }
    
    value = value.substr(start, end - start + 1);

    //std::cout << "Clipboard content is " << std::endl;
    std::cout << value << std::endl;
    //std::cout << std::endl;

    //for (size_t i=0; i<value.length(); i++){
      //char c = value[i];
      //std::cout << "[" << i << "] " << c << " (" << int(c) << ")" << std::endl;
    //}
  }

  return EXIT_SUCCESS;
}
