cmake_minimum_required(VERSION 3.13)
project(Contracts VERSION 1.0 LANGUAGES CXX)

add_library(CppContracts INTERFACE)
target_include_directories(CppContracts INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(Contracts::Library ALIAS CppContracts)