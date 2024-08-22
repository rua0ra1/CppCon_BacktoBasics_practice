cmake_minimum_required(VERSION 3.0.2)

project(AnimalTestSuite)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(
    animaltest
    Animaltest.cpp
    Animal.cpp
)

target_link_libraries(
    animaltest
  GTest::gtest_main
)

gtest_discover_tests(animaltest)