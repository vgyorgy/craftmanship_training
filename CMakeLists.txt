cmake_minimum_required(VERSION 3.0.0)
project(craftmanship_training VERSION 0.1.0)

#include(FetchContent)
#FetchContent_Declare(
#  googletest
#  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
#)
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

enable_testing()

file(GLOB SOURCES
  src/poker/*.cpp
)

include_directories(src)


add_executable(pokerTest tests/poker/unitTests/TestHand.cpp ${SOURCES})
target_link_libraries(pokerTest gtest_main ${GTEST_LIBRARIES} pthread)


include(GoogleTest)
gtest_discover_tests(pokerTest)
