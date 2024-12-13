cmake_minimum_required(VERSION 3.29)
project(untitled1)

set(CMAKE_CXX_STANDARD 26)

add_executable(untitled1 main.cpp
        BoardGame_Classes.h
        Four-in-a-row.h
        NumericalTicTacToe.h
        FourByFourTicTacToe.h
)
