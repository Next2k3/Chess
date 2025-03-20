#include "Queen.hpp"
#include "../Board.hpp"

std::vector<std::pair<int, int>> Queen::getRawMoves(int x, int y, const Board& board) const {
    std::vector<std::pair<int, int>> moves;

    // Wszystkie możliwe kierunki: pionowe, poziome i przekątne
    int directions[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},  // Rook (↑↓←→)
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1} // Bishop (↗↖↘↙)
    };

    for (auto& dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];

        while (board.isEmpty(newX, newY) || board.isEnemy(newX, newY, isWhitePiece())) {
            moves.push_back({newX, newY});  // Dodajemy ruch

            if (board.isEnemy(newX, newY, isWhitePiece())) {
                break;  // Jeśli trafiliśmy na wroga, zatrzymujemy ruch
            }

            newX += dir[0];
            newY += dir[1];
        }
    }

    return moves;
}
