cmake_minimum_required(VERSION 3.10)
project(banking)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# Основная библиотека
add_library(banking STATIC src/Account.cpp)
target_include_directories(banking PUBLIC include)

# Тесты
find_package(GTest REQUIRED)
add_executable(banking_tests test/AccountTest.cpp)
target_link_libraries(banking_tests banking ${GTEST_LIBRARIES} pthread)

enable_testing()
add_test(NAME banking_tests COMMAND banking_tests)
