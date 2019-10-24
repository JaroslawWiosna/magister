cmake_minimum_required(VERSION 3.0)

set (PROJECT_NAME
magister
)

project(${PROJECT_NAME})

option(BUILD_TESTS "Build tests" ON)
option(COVERAGE "Enable coverage" OFF)

set(CMAKE_CXX_STANDERD_REQUIRED ON)

if(COVERAGE)
  set(COMPILE_FLAGS "-ftest-coverage -fprofile-arcs")
endif()

# TODO(#16): Add debug option -g
# TODO(#17): Add make debugger or make gdb to start debugger if possible
set(COMPILE_FLAGS  "${COMPILE_FLAGS} -std=c++1z -Wall -O2 -Wno-missing-braces")

set (SOURCES
    src/main.cpp
    src/logger.cpp
    src/CacheOfSentences.cpp
    src/CompileTimeSentences_demo.cpp
    src/Lesson.cpp
    src/PoFileEntry.cpp
    src/Sentence.cpp
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

enable_testing()

if(BUILD_TESTS)
    set(GTEST_FLAGS "-lgtest")
    set(LINK_FLAGS "-lpthread")
    set(LINK_FLAGS "${GTEST_FLAGS} ${LINK_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )
    add_subdirectory(tests)
endif()
