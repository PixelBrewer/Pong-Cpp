cmake_minimum_required(VERSION 4.3)

project(Pong_Cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 6.0
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Menu.cpp
        src/headers/Menu.hpp
        src/Game.cpp
        src/headers/Game.hpp
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE raylib
)
