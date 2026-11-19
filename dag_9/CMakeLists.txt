cmake_minimum_required(VERSION 3.20)
project(day9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(day9_01_boundary 01_boundary.cpp)

add_executable(day9_02_debug 02_debug.cpp)

add_executable(day9_03_failing_test 03_failing_test.cpp)

add_executable(day9_04_source_location 04_source_location.cpp)

add_executable(day9_05_expected_cpp23 05_expected_cpp23.cpp)

add_executable(day9 main.cpp)

enable_testing()

add_executable(day9_test_alarm_boundaries tests/test_alarm_boundaries.cpp)
add_test(NAME day9_alarm_boundaries COMMAND day9_test_alarm_boundaries)

add_executable(day9_test_alarm_invalid tests/test_alarm_invalid.cpp)
add_test(NAME day9_alarm_invalid COMMAND day9_test_alarm_invalid)

add_executable(day9_test_parser_valid tests/test_parser_valid.cpp)
add_test(NAME day9_parser_valid COMMAND day9_test_parser_valid)

add_executable(day9_test_parser_format tests/test_parser_format.cpp)
add_test(NAME day9_parser_format COMMAND day9_test_parser_format)

add_executable(day9_test_parser_range tests/test_parser_range.cpp)
add_test(NAME day9_parser_range COMMAND day9_test_parser_range)

add_executable(day9_test_statistics_values tests/test_statistics_values.cpp)
add_test(NAME day9_statistics_values COMMAND day9_test_statistics_values)

add_executable(day9_test_statistics_rejected_update tests/test_statistics_rejected_update.cpp)
add_test(NAME day9_statistics_rejected_update COMMAND day9_test_statistics_rejected_update)

add_executable(day9_test_statistics_empty tests/test_statistics_empty.cpp)
add_test(NAME day9_statistics_empty COMMAND day9_test_statistics_empty)

set_tests_properties(
    day9_alarm_boundaries
    day9_alarm_invalid
    day9_parser_valid
    day9_parser_format
    day9_parser_range
    day9_statistics_values
    day9_statistics_rejected_update
    day9_statistics_empty
    PROPERTIES TIMEOUT 10
)
