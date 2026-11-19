cmake_minimum_required(VERSION 3.20)
project(day11 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(day11_01_function 01_function.cpp)

add_executable(day11_02_class 02_class.cpp)

add_executable(day11_03_vector 03_vector.cpp)

add_executable(day11_04_invalidation 04_invalidation.cpp)

add_executable(day11_05_array 05_array.cpp)

add_executable(day11_06_list 06_list.cpp)

add_executable(day11_07_map 07_map.cpp)

add_executable(day11_08_unordered 08_unordered.cpp)

add_executable(day11 main.cpp)

add_executable(day11_09_concepts_cpp20 09_concepts_cpp20.cpp)

add_executable(day11_10_span_cpp20 10_span_cpp20.cpp)
