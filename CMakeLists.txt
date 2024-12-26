cmake_minimum_required(VERSION 3.20)

project(console_piano VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(console_piano)

target_sources(console_piano PRIVATE
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

target_include_directories(console_piano PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
