cmake_minimum_required(VERSION 3.20)

project(day7 LANGUAGES CXX)

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

course_example(day7 main.cpp)
course_example(day7_01_references 01_references.cpp)
course_example(day7_02_pointers 02_pointers.cpp)
course_example(day7_03_const 03_const.cpp)
course_example(day7_04_storage 04_storage.cpp)
course_example(day7_05_array 05_array.cpp)
course_example(day7_06_lifetime 06_lifetime.cpp)

course_example(day7_07_span_cpp20 07_span_cpp20.cpp)
