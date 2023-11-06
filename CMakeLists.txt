cmake_minimum_required(VERSION 3.0.0)
project(omg-seminar VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(omg-seminar INTERFACE)
target_include_directories(omg-seminar INTERFACE include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(lib)
add_subdirectory(test)