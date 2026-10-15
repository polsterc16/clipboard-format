cmake_minimum_required(VERSION 4.0)
project(clipboard-format 
    VERSION 0.1.0 
    LANGUAGES C CXX
)
include(CMakePrintHelpers)
cmake_print_variables(CMAKE_C_COMPILER CMAKE_MAJOR_VERSION DOES_NOT_EXIST CMAKE_GENERATOR)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "CMAKE_EXPORT_COMPILE_COMMANDS")
set( CMAKE_EXPORT_COMPILE_COMMANDS on )

add_executable(${PROJECT_NAME} src/main.cpp)

# add "external" dir
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_HOME_DIRECTORY}/external)

# add clip
set(CLIP_ENABLE_IMAGE OFF CACHE INTERNAL "Compile with support to copy/paste images")
set(CLIP_EXAMPLES OFF CACHE INTERNAL "Compile clip examples")
set(CLIP_TESTS OFF CACHE INTERNAL "Compile clip tests")
if(UNIX AND NOT APPLE)
    set(CLIP_X11_WITH_PNG OFF CACHE INTERNAL "Compile with libpng to support copy/paste image in png format")
endif()

set(CLIP_DIR "${CMAKE_HOME_DIRECTORY}/external/clip")
add_subdirectory(${CLIP_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE clip)
