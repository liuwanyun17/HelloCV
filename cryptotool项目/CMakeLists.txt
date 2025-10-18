cmake_minimum_required(VERSION 3.10)
project(Cryptotool)

include_directories(.)

add_executable(Cryptotool 
    src/main.cpp
    src/menu.cpp 
    src/crypto.cpp
    src/filehandler.cpp
    include/Crypto.h
    include/FileHandler.h
    include/Menu.h
)