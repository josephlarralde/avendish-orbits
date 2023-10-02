cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(AvndOrbits)

message(STATUS "MAX SDK PATH : ${AVND_MAXSDK_PATH}")
message(STATUS "CMAKE PREFIX PATH : ${CMAKE_PREFIX_PATH}")

include(dependencies.cmake)

add_library(AvndOrbits STATIC
  src/Model.cpp
  src/Model.hpp
  src/UI.hpp
  src/Processor.hpp
)

avnd_make_all(
  TARGET AvndOrbits
  MAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/src/Processor.hpp"
  MAIN_CLASS AvndOrbits
  C_NAME orbits
)
