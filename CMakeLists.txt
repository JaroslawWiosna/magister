cmake_minimum_required(VERSION 3.0)

set (PROJECT_NAME
magister
)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDERD_REQUIRED ON)

set (SOURCES
    src/main.cpp
    src/logger.cpp
    src/PoFileEntry.cpp
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

