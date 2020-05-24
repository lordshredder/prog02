cmake_minimum_required(VERSION 3.16)
project(Ueb03)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ueb03 main.cpp Article.h Article.cpp TestStorage.cpp TestStorage.h StorageDialogue.cpp StorageDialogue.h)