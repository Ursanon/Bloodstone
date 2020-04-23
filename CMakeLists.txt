cmake_minimum_required (VERSION 3.9)

project(Bloodstone)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

set(ENGINE_DIR "${PROJECT_SOURCE_DIR}/engine")
set(GAME_DIR "${PROJECT_SOURCE_DIR}/game")

set(ENGINE_INCLUDE_DIR "${ENGINE_DIR}/include")
set(ENGINE_SRC_DIR "${ENGINE_DIR}/src")

set(GAME_INCLUDE_DIR "${GAME_DIR}/include")
set(GAME_SRC_DIR "${GAME_DIR}/src")

include_directories("${ENGINE_INCLUDE_DIR}")
include_directories("${ENGINE_SRC_DIR}")

include_directories("${GAME_INCLUDE_DIR}")
include_directories("${GAME_SRC_DIR}")

file(GLOB_RECURSE ALL_SRC
    "${ENGINE_INCLUDE_DIR}/*.hpp"
    "${ENGINE_SRC_DIR}/*.cpp"

    "${GAME_INCLUDE_DIR}/*.hpp"
    "${GAME_SRC_DIR}/*.cpp"
    )

add_executable(Bloodstone "${ALL_SRC}")

target_link_libraries(Bloodstone ${SDL2_LIBRARIES})

#Copy dll
add_custom_command(TARGET Bloodstone POST_BUILD 
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   "${SDL2_DLL}"
                   ${CMAKE_BINARY_DIR})

#Copy assets
add_custom_command(TARGET Bloodstone POST_BUILD 
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   "${GAME_DIR}/Assets"
                   "${CMAKE_BINARY_DIR}/Assets")