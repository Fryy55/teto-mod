cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(Tetomod VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/include/FryyUtils_v1.0.hpp
    src/include/FryyUtils_v1.0.cpp
    src/include/FryyGIF_v1.0.hpp
    src/include/FryyGIF_v1.0.cpp
    src/include/FryyVideo_v1.0.hpp
    src/include/FryyVideo_v1.0.cpp
    src/Teto.cpp
    # Add any extra C++ source files here
)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

setup_geode_mod(${PROJECT_NAME})
