cmake_minimum_required(VERSION 3.10)
project(eosio-cmake-tutorial)

################################
## Project
################################
set(PROJECT_VERSION_MAJOR "0")
set(PROJECT_VERSION_MINOR "1")
set(PROJECT_VERSION_PATCH "0")
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
set(VERSION ${PROJECT_VERSION})

message("\n-- Configuring ${PROJECT_NAME} ${PROJECT_VERSION}...\n")

################################
## Cmake dependencies
################################
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)

include(cmake/eosiosdk.cmake)
include(cmake/eosiosdk-util.cmake)
include(cmake/FindEOSIOSDKLibs.cmake)

################################
## Compiler Flags
################################
set(CMAKE_CXX_STANDARD 14)

################################
# Library Build
################################
# target hello
add_eosio_wasm_library(hello CONTRACT SOURCES src/hello.cpp)
target_eosio_wasm_compile_definitions(hello PUBLIC -DBOOST_DISABLE_ASSERTS -DBOOST_EXCEPTION_DISABLE)
target_eosio_wasm_include_directories(hello
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>)
# $<INSTALL_INTERFACE:include>)
target_eosio_wasm_link_libraries(hello eosio libc++ libc musl Boost)

add_eosio_wasm_abi(hello HEADERS include/contracts/hello.hpp)

# target tic tac toe
add_eosio_wasm_library(tic_tac_toe CONTRACT SOURCES src/tic_tac_toe.cpp)
target_eosio_wasm_compile_definitions(tic_tac_toe PUBLIC -DBOOST_DISABLE_ASSERTS -DBOOST_EXCEPTION_DISABLE)
target_eosio_wasm_include_directories(tic_tac_toe
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>)
# $<INSTALL_INTERFACE:include>)
target_eosio_wasm_link_libraries(tic_tac_toe eosio libc++ libc musl Boost)

add_eosio_wasm_abi(tic_tac_toe HEADERS include/contracts/tic_tac_toe.hpp)
################################
## Install
################################

eosio_wasm_install(hello CONTRACT
        CODE DESTINATION "${CMAKE_INSTALL_FULL_CODEDIR}/hello"
        ABI DESTINATION "${CMAKE_INSTALL_FULL_ABIDIR}/hello")
eosio_wasm_install(tic_tac_toe CONTRACT
        CODE DESTINATION "${CMAKE_INSTALL_FULL_CODEDIR}/tic_tac_toe"
        ABI DESTINATION "${CMAKE_INSTALL_FULL_ABIDIR}/tic_tac_toe")
