cmake_minimum_required(VERSION 3.28)
project(array)

set(CMAKE_CXX_STANDARD 17)


add_executable(test01 chapter01/symmetric_matrix.cpp
        chapter01/symmetric_matrix.h
        chapter01/test01.cpp)