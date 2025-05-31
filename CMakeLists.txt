cmake_minimum_required(VERSION 3.10)
project(banking LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Настройки покрытия кода
option(ENABLE_COVERAGE "Enable coverage reporting" OFF)
if(ENABLE_COVERAGE)
    add_compile_options(--coverage -fprofile-arcs -ftest-coverage)
    add_link_options(--coverage)
endif()

# Основная библиотека
add_library(banking STATIC
    src/Account.cpp
    src/Transaction.cpp
)

target_include_directories(banking PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Подключаем GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Тесты
add_executable(banking_tests
    test/AccountTest.cpp
    test/TransactionTest.cpp
    test/MockBanking.cpp
)

target_link_libraries(banking_tests
    PRIVATE
    banking
    GTest::GTest
    GMock::GMock
)

include(GoogleTest)
gtest_discover_tests(banking_tests)

# Генерация отчетов о покрытии
if(ENABLE_COVERAGE)
    find_program(GCOVR gcovr)
    if(GCOVR)
        add_custom_target(coverage_report
            COMMAND ${GCOVR} -r .. --exclude-unreachable-branches --exclude-throw-branches --html-details -o coverage.html
            COMMAND ${GCOVR} -r .. --branches --print-summary
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Generating code coverage report"
        )
    endif()
endif()
