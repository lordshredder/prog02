cmake_minimum_required(VERSION 3.16)
project(Ueb01)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ueb01 main.cpp Person.cpp Person.h PersonStorage.cpp PersonStorage.h Tests/MockInput.cpp Tests/MockInput.h)
add_subdirectory(Tests)