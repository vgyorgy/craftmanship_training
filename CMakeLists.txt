cmake_minimum_required(VERSION 3.0.0)
project(craftmanship_training VERSION 0.1.0)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

enable_testing()

file(GLOB SOURCES
  src/runner_app/*.cpp
)

include_directories(src)
add_executable(craftmanship_training_test tests/runner_app/init_project_test.cpp ${SOURCES})
target_link_libraries(craftmanship_training_test gtest_main ${GTEST_LIBRARIES} pthread)

include(GoogleTest)
gtest_discover_tests(craftmanship_training_test)

