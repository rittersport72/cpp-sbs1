cmake_minimum_required(VERSION 3.14)
project(sbs1 LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# library
add_library(sbs1 STATIC)

file(GLOB_RECURSE sources "source/*.cpp" "source/*.h")

target_sources(sbs1 PRIVATE ${sources})

target_include_directories(sbs1 PUBLIC "source/")

# executable
add_executable(sbs1test "test/Test.cpp")

target_link_libraries(sbs1test PRIVATE sbs1)