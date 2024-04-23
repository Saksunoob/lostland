cmake_minimum_required(VERSION 3.22)

find_package(SDL2)

project(
  LostLand
  VERSION 0.1
  LANGUAGES CXX)

set(SOURCE_FILES)
file(GLOB_RECURSE SOURCE_FILES "../src/*.cpp")

add_executable(LostLand ${SOURCE_FILES})
target_include_directories(LostLand PRIVATE "../include")
target_include_directories(LostLand PRIVATE "../lib")
target_link_libraries(LostLand SDL2)


