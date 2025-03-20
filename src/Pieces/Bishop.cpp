#include "Bishop.hpp"
#include "../Board.hpp"

std::vector<std::pair<int, int>> Bishop::getRawMoves(int x, int y, const Board& board) const {
    std::vector<std::pair<int, int>> moves;

    // Cztery kierunki po przekątnych
    int directions[4][2] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    for (auto& dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];

        while (board.isEmpty(newX, newY) || board.isEnemy(newX, newY, isWhitePiece())) {
            moves.push_back({newX, newY});  // Dodajemy możliwy ruch

            if (board.isEnemy(newX, newY, isWhitePiece())) {
                break;  // Jeśli natrafiliśmy na przeciwnika, nie idziemy dalej
            }

            newX += dir[0];
            newY += dir[1];
        }
    }

    return moves;
}
