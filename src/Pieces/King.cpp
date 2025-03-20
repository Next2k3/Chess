#include "King.hpp"
#include "../Board.hpp"

std::vector<std::pair<int, int>> King::getRawMoves(int x, int y, const Board& board) const {
    std::vector<std::pair<int, int>> moves;

    // 8 możliwych kierunków ruchu
    int directions[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},  // Pionowo i poziomo
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1} // Przekątne
    };

    for (auto& dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];

        if (board.isEmpty(newX, newY) || board.isEnemy(newX, newY, isWhitePiece())) {
            moves.push_back({newX, newY});  // Król może wejść na to pole
        }
    }

    return moves;
}
