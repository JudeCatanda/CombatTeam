cmake_minimum_required(VERSION 3.29)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CXX_COMPILER g++)
set(CMAKE_CXX_COMPILER g++)

set(LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(INCL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIBS_TO_LINK opengl32 glfw3 -static-libgcc -static-libstdc++ -static)

project(CombatTeam VERSION 0.1 LANGUAGES CXX)

add_subdirectory(src/Game)
add_subdirectory(src/Engine)
add_subdirectory(src)
