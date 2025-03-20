cmake_minimum_required(VERSION 3.10)
project(ChessGame)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/Game.cpp src/Game.hpp
    src/Board.cpp src/Board.hpp
    src/Piece.cpp src/Piece.hpp
    src/Pieces/Pawn.cpp src/Pieces/Pawn.hpp
    src/Pieces/Knight.cpp src/Pieces/Knight.hpp
    src/Pieces/Bishop.cpp src/Pieces/Bishop.hpp
    src/Pieces/Rook.cpp src/Pieces/Rook.hpp
    src/Pieces/Queen.cpp src/Pieces/Queen.hpp
    src/Pieces/King.cpp src/Pieces/King.hpp
)

add_executable(chess ${SOURCES})

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(chess PRIVATE -03)
endif()
