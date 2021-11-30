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
    ../src/*.cpp
)

add_library( dummies STATIC ${SOURCES} )

add_executable(craftmanship_training_test craftmanship_training_test.cpp)
target_link_libraries(craftmanship_training_test gtest_main dummies)

include(GoogleTest)
gtest_discover_tests(craftmanship_training_test)
