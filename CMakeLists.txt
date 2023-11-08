cmake_minimum_required(VERSION 3.5)
project(testing VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(seminar INTERFACE)
target_include_directories(seminar INTERFACE "include")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(lib)
add_subdirectory(test)