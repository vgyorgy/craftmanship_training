cmake_minimum_required(VERSION 3.0.0)
project(craftmanship_training VERSION 0.1.0)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB SOURCES
  src/runner_app/*.cpp
)

include_directories(src)
add_executable(craftmanship_training_test tests/runner_app/init_project_test.cpp ${SOURCES})
target_link_libraries(craftmanship_training_test gtest_main)

include(GoogleTest)
gtest_discover_tests(craftmanship_training_test)

