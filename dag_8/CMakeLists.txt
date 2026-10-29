cmake_minimum_required(VERSION 3.20)

project(day8 LANGUAGES CXX)

function(course_example target source)
    add_executable(${target} ${source})
    target_compile_features(${target} PRIVATE cxx_std_23)
    set_target_properties(${target} PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
    )

    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endfunction()

course_example(day8 main.cpp)
course_example(day8_01_raii 01_raii.cpp)
course_example(day8_02_unique 02_unique.cpp)
course_example(day8_03_array 03_array.cpp)
course_example(day8_04_shared 04_shared.cpp)
course_example(day8_05_weak 05_weak.cpp)
course_example(day8_06_exception 06_exception.cpp)

course_example(day8_extra_20_array extra_20_array.cpp)
