cmake_minimum_required(VERSION 3.10)
project(lab_4 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

include_directories(include)

add_executable(lab4_main src/main.cpp)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(lab4_tests
    tests/test_triangle.cpp
    tests/test_square.cpp
    tests/test_octagon.cpp
    tests/test_array.cpp
)

target_link_libraries(lab4_tests
    gtest_main
    gtest
)

include(GoogleTest)
gtest_discover_tests(lab4_tests)

install(TARGETS lab4_main DESTINATION bin)

