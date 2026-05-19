cmake_minimum_required(VERSION 3.20)

project(esercitazione9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(test_visite 
    main.cpp 
    unidirected_edge.hpp 
    unidirected_graph.hpp 
    containers.hpp 
    graph_visit.hpp 
    write_graph_dot.hpp
	recursive_dfs.hpp
	dijkstra.hpp
)