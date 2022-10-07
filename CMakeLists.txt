cmake_minimum_required(VERSION 3.0.0)
project(sbs1 VERSION 0.1.0)

file(GLOB_RECURSE sources source/*.cpp source/*.h)

add_library(sbs1 STATIC)

target_sources(sbs1 PRIVATE ${sources})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
