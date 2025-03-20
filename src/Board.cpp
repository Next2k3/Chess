#include "Board.hpp"
#include "Pieces/King.hpp"
#include <iostream>

Board::Board() {
    grid.resize(8, std::vector<Piece*>(8,nullptr));
    //TODO inicjalizacja figur
}

Board::~Board() {
    for (auto& row : grid) {
        for (auto& piece : row){
            delete piece;
        }
    }
}

bool Board::isEmpty(int x, int y) const {
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && grid[x][y] == nullptr);
}

bool Board::isEnemy(int x, int y, bool isWhite) const {
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && grid[x][y] != nullptr && grid[x][y]->isWhitePiece() != isWhite);
}

std::vector<std::pair<int, int>> Board::getLegalMoves(int x, int y) {
    Piece* piece = getPiece(x, y);
    if (!piece) return {};
    
    std::vector<std::pair<int, int>> moves;
    std::vector<std::pair<int, int>> rawMoves = piece->getRawMoves(x, y, *this);

    for (const auto& move : rawMoves) {
        int newX = move.first, newY = move.second;

        // Symulujemy ruch
        Piece* captured = grid[newX][newY];
        grid[newX][newY] = grid[x][y];
        grid[x][y] = nullptr;

        // Sprawdzamy, czy nasz król nie jest w szachu
        if (!isCheck(piece->isWhitePiece())) {
            moves.push_back(move);
        }

        // Cofamy symulację
        grid[x][y] = grid[newX][newY];
        grid[newX][newY] = captured;
    }

    return moves;
}

bool Board::isCheck(bool isWhite) const {
    int kingX = -1, kingY = -1;

    // Znajdujemy króla
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (grid[x][y] && grid[x][y]->isWhitePiece() == isWhite && dynamic_cast<King*>(grid[x][y])) {
                kingX = x;
                kingY = y;
            }
        }
    }

    // Sprawdzamy, czy jakaś figura atakuje króla
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (grid[x][y] && grid[x][y]->isWhitePiece() != isWhite) {
                auto moves = grid[x][y]->getRawMoves(x, y, *this);
                for (const auto& move : moves) {
                    if (move.first == kingX && move.second == kingY) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Board::movePiece(int fromX, int fromY, int toX, int toY) {
    Piece* movedPiece = grid[fromX][fromY];

    if (movedPiece && dynamic_cast<Pawn*>(movedPiece) && abs(fromY - toY) == 2) {
        setEnPassantTarget(std::make_pair(fromX, (fromY + toY)/2));
    } else {
        setEnPassantTarget(std::nullopt);
    }

    grid[toX][toY] = movedPiece;
    grid[fromX][fromY] = nullptr;
}