cmake_minimum_required(VERSION 3.21)
project(PuzzleEx)

set(CMAKE_CXX_STANDARD 14)

add_executable(PuzzleEx main.cpp PuzzleContainer.cpp PuzzleContainer.h PuzzleRow.cpp PuzzleRow.h)
