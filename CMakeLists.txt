cmake_minimum_required(VERSION 3.2)

project(JDILLA)

set(CMAKE_CXX_STANDARD 20)

set(HEADERS_DIR "${CMAKE_SOURCE_DIR}/headers")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/sources")

include_directories(${HEADERS_DIR})
include_directories(${SOURCE_DIR})

file(GLOB CPPS "${SOURCE_DIR}/*.cpp")
file(GLOB HEADERS "${HEADERS_DIR}/*.h")
file(GLOB CPPHEADERS "${HEADERS_DIR}/*.hpp")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(${PROJECT_NAME} ${CPPS} ${HEADERS} ${CPPHEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE ${HEADERS_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCE_DIR})
