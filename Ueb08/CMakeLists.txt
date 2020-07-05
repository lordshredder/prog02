cmake_minimum_required(VERSION 3.16)
project(Ueb08)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ueb08 main.cpp Project.cpp Project.h ProjectComponent.cpp ProjectComponent.h Task.cpp Task.h Product.cpp Product.h ProjectDialogue.cpp ProjectDialogue.h safeRead.h ExceptionChecker.h)