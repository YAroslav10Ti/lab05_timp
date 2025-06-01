cmake_minimum_required(VERSION 3.10)
project(banking)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

# Основная библиотека
add_library(banking STATIC src/Account.cpp)
target_include_directories(banking PUBLIC include)

# Тесты
find_package(GTest REQUIRED)
add_executable(banking_tests test/AccountTest.cpp)
target_link_libraries(banking_tests PRIVATE banking GTest::GTest GTest::Main)

include(GoogleTest)
gtest_discover_tests(banking_tests)
