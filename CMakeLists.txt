cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME Complex)
project(${PROJECT_NAME})

set(application ComplexApplication)
set(library ComplexLibrary)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Config" FORCE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ComplexLibrary)

add_subdirectory(ComplexLibrary)
add_subdirectory(ComplexApplication)
add_subdirectory(gtest)
add_subdirectory(test)

