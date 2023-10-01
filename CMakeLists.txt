cmake_minimum_required(VERSION 3.5)

project(07.homework)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        f8d7d77 # release-1.14.0
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    

add_executable(container_tests tests/vector_tests.cpp tests/list_tests.cpp)
target_include_directories(container_tests PRIVATE include)
# target_include_directories(container PRIVATE src)
set_target_properties(container_tests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

target_link_libraries(container_tests 
					PUBLIC
					gtest gtest_main)


if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(container_tests PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(container PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()