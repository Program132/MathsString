cmake_minimum_required(VERSION 3.22)
project(MathsString)

set(CMAKE_CXX_STANDARD 23)

add_executable(MathsString
        main.cpp main.cpp src/Tokenizer.cpp src/Tokenizer.h src/Parser.h src/Utils/Converts.h)