cmake_minimum_required(VERSION 3.0.0)
project(craftmanship_training VERSION 0.1.0)

include_directories(inc)
file(GLOB SOURCES
    inc/*.h
    src/*.cpp
)

add_executable(craftmanship_training ${SOURCES})
target_link_libraries(craftmanship_training)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(tests)

