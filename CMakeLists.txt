cmake_minimum_required(VERSION 3.10)
project(centrality)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(centrality
    main.cpp
    Graph.cpp
    Dijkstra.cpp
)

target_compile_options(centrality PRIVATE 
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    -Wconversion
    -Wsign-conversion
    -Wshadow
    -Wold-style-cast
    -Wnull-dereference
    -O3
    -march=native
    -mtune=native
)

target_link_options(centrality PRIVATE -flto)