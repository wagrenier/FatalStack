cmake_minimum_required(VERSION 3.17)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/vcpkg.exe")
    execute_process(COMMAND bootstrap-vcpkg.bat WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg)
endif()

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")

project(FatalStack CXX)

set(CMAKE_CXX_STANDARD 14)

if(NOT $SDL_FOUND)
    execute_process(COMMAND vcpkg.exe install sdl2 COMMAND vcpkg.exe install sdl2image WORKING_DIRECTORY ./vcpkg)
endif()

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2-image CONFIG REQUIRED)

add_executable(FatalStack main.cpp)
target_link_libraries(FatalStack PRIVATE SDL2::SDL2 SDL2::SDL2_image SDL2::SDL2main)