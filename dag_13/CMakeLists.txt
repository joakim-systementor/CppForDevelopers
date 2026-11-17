cmake_minimum_required(VERSION 3.20)
project(day13 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(day13_01_thread 01_thread.cpp)
target_link_libraries(day13_01_thread PRIVATE Threads::Threads)

add_executable(day13_02_capture 02_capture.cpp)
target_link_libraries(day13_02_capture PRIVATE Threads::Threads)

add_executable(day13_03_local_results 03_local_results.cpp)
target_link_libraries(day13_03_local_results PRIVATE Threads::Threads)

add_executable(day13_04_atomic 04_atomic.cpp)
target_link_libraries(day13_04_atomic PRIVATE Threads::Threads)

add_executable(day13_05_worker_error 05_worker_error.cpp)
target_link_libraries(day13_05_worker_error PRIVATE Threads::Threads)

add_executable(day13 main.cpp)
target_link_libraries(day13 PRIVATE Threads::Threads)

add_executable(day13_06_jthread 06_jthread.cpp)
target_link_libraries(day13_06_jthread PRIVATE Threads::Threads)

add_executable(day13_07_stop 07_stop.cpp)
target_link_libraries(day13_07_stop PRIVATE Threads::Threads)
