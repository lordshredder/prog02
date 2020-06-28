cmake_minimum_required(VERSION 3.16)
project(Ube007)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ube07 main.cpp Clothing.cpp Clothing.h ElectronicDevice.cpp ElectronicDevice.h Article.cpp Article.h Storage.cpp Storage.h StorageDialogue.cpp StorageDialogue.h MockInput.cpp MockInput.h safeRead.h StorageExceptions.h ExceptionChecker.h)