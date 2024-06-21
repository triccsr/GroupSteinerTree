cmake_minimum_required(VERSION 3.5.0)
project(SkyHL VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_CXX_FLAGS "-O3")

add_compile_options(-Wall -Wextra -Wconversion -Wshadow -fdiagnostics-color=always)

include(CTest)
enable_testing()

# add_executable(SkySHL main.cpp)

add_library(ysgraph STATIC ${CMAKE_CURRENT_SOURCE_DIR}/ysgraph_20210203/dummy.cpp)
target_include_directories(ysgraph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/boost_1_85_0 ${CMAKE_CURRENT_SOURCE_DIR}/ysgraph_20210203)

add_subdirectory("C++\ codes")


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
