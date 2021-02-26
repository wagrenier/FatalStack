cmake_minimum_required(VERSION 3.17)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")

project(FatalStack)

set(CMAKE_CXX_STANDARD 14)

if($SDL_FOUND)
    execute_process(COMMAND vcpkg install sdl2 COMMAND vcpkg install sdl2image WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg)
endif()

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2-image CONFIG REQUIRED)

add_executable(FatalStack main.cpp)
target_link_libraries(FatalStack PRIVATE SDL2::SDL2 SDL2::SDL2_image SDL2::SDL2main)