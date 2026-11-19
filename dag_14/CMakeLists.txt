cmake_minimum_required(VERSION 3.20)
project(day14 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(day14_01_mutex 01_mutex.cpp)
target_link_libraries(day14_01_mutex PRIVATE Threads::Threads)

add_executable(day14_02_unique_lock 02_unique_lock.cpp)
target_link_libraries(day14_02_unique_lock PRIVATE Threads::Threads)

add_executable(day14_03_scoped_lock 03_scoped_lock.cpp)
target_link_libraries(day14_03_scoped_lock PRIVATE Threads::Threads)

add_executable(day14_04_condition 04_condition.cpp)
target_link_libraries(day14_04_condition PRIVATE Threads::Threads)

add_executable(day14_05_queue 05_queue.cpp)
target_link_libraries(day14_05_queue PRIVATE Threads::Threads)

add_executable(day14_06_latch 06_latch.cpp)
target_link_libraries(day14_06_latch PRIVATE Threads::Threads)

add_executable(day14 main.cpp)
target_link_libraries(day14 PRIVATE Threads::Threads)

add_executable(day14_tests tests.cpp)
target_link_libraries(day14_tests PRIVATE Threads::Threads)

enable_testing()
add_test(NAME day14_contract COMMAND day14_tests)
set_tests_properties(day14_contract PROPERTIES TIMEOUT 10)

add_executable(day14_07_counting_semaphore 07_counting_semaphore.cpp)
target_link_libraries(day14_07_counting_semaphore PRIVATE Threads::Threads)

add_executable(day14_08_binary_semaphore 08_binary_semaphore.cpp)
target_link_libraries(day14_08_binary_semaphore PRIVATE Threads::Threads)
