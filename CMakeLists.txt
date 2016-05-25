cmake_minimum_required(VERSION 3.3)
project(ajedrez)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp alfil.cpp caballo.cpp casilla.cpp juego.cpp jugador.cpp peon.cpp pieza.cpp reina.cpp rey.cpp tablero.cpp torre.cpp)
add_executable(ajedrez ${SOURCE_FILES})