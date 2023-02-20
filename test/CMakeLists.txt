cmake_minimum_required(VERSION 3.14)
project(test LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# executable
add_executable(sbs1test "source/Test.cpp")

target_link_libraries(sbs1test PRIVATE sbs1)