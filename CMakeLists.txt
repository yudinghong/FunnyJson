cmake_minimum_required(VERSION 3.22)
project(funny_json)

set(CMAKE_CXX_STANDARD 11)

add_executable(funny_json main.cpp lib/FunnyJson.cpp lib/FunnyJson.h lib/FunnyJsonDoc.cpp lib/FunnyJsonDoc.h lib/FunnyJsonObject.cpp lib/FunnyJsonObject.h lib/FunnyJsonEnum.h)
