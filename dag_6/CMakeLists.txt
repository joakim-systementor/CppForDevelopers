cmake_minimum_required(VERSION 3.20)

project(day6 LANGUAGES CXX)

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

course_example(day6_01_compound 01_compound.cpp)
course_example(day6_02_add 02_add.cpp)
course_example(day6_03_compare 03_compare.cpp)
course_example(day6_04_stream 04_stream.cpp)
course_example(day6_05_account 05_account.cpp)
course_example(day6 main.cpp)

course_example(day6_06_compare_cpp20 06_compare_cpp20.cpp)
