cmake_minimum_required(VERSION 3.15)
project(APA C)

set(CMAKE_C_STANDARD 99)

add_executable(APA main.c GRAPH.c GRAPH.h SIM.c SIM.h grafo.txt)