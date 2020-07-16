cmake_minimum_required(VERSION 3.16)
project(template)

set(CMAKE_CXX_STANDARD 17)

add_executable(template main.cpp Array.cpp Array.h FixedStack.cpp FixedStack.h AbstractStack.h require.h)