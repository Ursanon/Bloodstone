cmake_minimum_required (VERSION 3.9)

project(Bloodstone)

set(CMAKE_CXX_STANDARD 17)

set(ENGINE_DIR "${PROJECT_SOURCE_DIR}/engine")
set(GAME_DIR "${PROJECT_SOURCE_DIR}/game")

set(ENGINE_INCLUDE_DIR "${ENGINE_DIR}/include")
set(ENGINE_SRC_DIR "${ENGINE_DIR}/src")

set(GAME_INCLUDE_DIR "${GAME_DIR}/include")
set(GAME_SRC_DIR "${GAME_DIR}/src")

include_directories("${ENGINE_INCLUDE_DIR}")
include_directories("${GAME_INCLUDE_DIR}")

set(SFML_LIBRARIES "${SFML_LIBRARIES}")

file(GLOB_RECURSE ALL_SRC
    "${ENGINE_INCLUDE_DIR}/*.hpp"
    "${ENGINE_SRC_DIR}/*.cpp"

    "${GAME_INCLUDE_DIR}/*.hpp"
    "${GAME_SRC_DIR}/*.cpp"
    )

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_executable(Bloodstone ${ALL_SRC})
target_link_libraries(Bloodstone sfml-system sfml-window sfml-graphics sfml-audio)

#Copy assets
add_custom_command(TARGET Bloodstone POST_BUILD 
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   "${GAME_DIR}/Assets"
                   "${CMAKE_BINARY_DIR}/Assets")

#Copy lib
add_custom_command(TARGET Bloodstone POST_BUILD 
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   "${SFML_BIN}"
                   "${CMAKE_BINARY_DIR}")