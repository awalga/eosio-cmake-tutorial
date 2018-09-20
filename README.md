# eosio-cmake-examples
An example of Clion project using CMake build scripts

## Table of Contents

- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Usage](#usage)
  - [Build from CLion](#build-from-clion)
  - [Build from cmd line](#build-from-cmd-line)
- [How it works](#how-it-works)
  - [Step 1](#step-1)
  - [Step 2](#step-2)
  - [Step 3](#step-3)
- [License](#license)

## Overview
This is an example of eosio smart contract build based on Cmake and Clion. The projects containes 2 targets `hello`, `tic_tac_toe`.

## Prerequisites
Please see [eosio cmake prerequisites](https://github.com/awalga/eosio-cmake/blob/master/README.md#prerequisites)

## Usage

### Build from CLion
CMake handles our dependencies and detects our targets. Hence target are accessible from CLion UI.

### Build from cmd line
```
git clone https://github.com/awalga/eosio-cmake-examples.git
cd eosio-cmake-examples
mkdir build && cd build
cmake ..
make contracts
```

## How it works

### Step 1:
We imports `eosiosdk.cmake` `eosiosdk-util.cmake` `FindEOSIOSDKLibs.cmake` available here [](https://github.com/awalga/eosio-cmake) in our root CMakeLists.
```
################################
## Cmake dependencies
################################

include(cmake/eosiosdk.cmake)
include(cmake/eosiosdk-util.cmake)

################################
## Dependencies
################################
include(cmake/FindEOSIOSDKLibs.cmake)
```
### Step 2:

We define our targets

```
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
```

### Step 3:
We define install targets:
```
################################
## Install
################################

eosio_wasm_install(hello CONTRACT
        CODE DESTINATION "${CMAKE_INSTALL_FULL_CODEDIR}/hello"
        ABI DESTINATION "${CMAKE_INSTALL_FULL_ABIDIR}/hello")
eosio_wasm_install(tic_tac_toe CONTRACT
        CODE DESTINATION "${CMAKE_INSTALL_FULL_CODEDIR}/tic_tac_toe"
        ABI DESTINATION "${CMAKE_INSTALL_FULL_ABIDIR}/tic_tac_toe")
```
## License
MIT

