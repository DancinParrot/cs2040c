cmake_minimum_required(VERSION 3.14)
project(cs2040c_pe1-2021-pt2)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_compile_options(-Wall -Wextra)

# add_library(SimpleLinkedListTemplate part1Submission.hpp)

add_executable(
  main
  main.cpp
)
target_link_libraries(
  main
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(main)
