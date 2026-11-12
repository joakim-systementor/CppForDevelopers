cmake_minimum_required(VERSION 3.20)
project(day12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(day12_01_iterators 01_iterators.cpp)

add_executable(day12_02_sort 02_sort.cpp)

add_executable(day12_03_find_count 03_find_count.cpp)

add_executable(day12_04_capture 04_capture.cpp)

add_executable(day12_05_transform 05_transform.cpp)

add_executable(day12_06_erase 06_erase.cpp)

add_executable(day12_extra_23_ranges extra_23_ranges.cpp)

add_executable(day12 main.cpp)
