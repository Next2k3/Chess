#include "Pawn.hpp"
#include "../Board.hpp"

std::vector<std::pair<int, int>> Pawn::getRawMoves(int x, int y, const Board& board) const {
    std::vector<std::pair<int, int>> moves;
    
    int direction = isWhitePiece() ? -1 : 1;  // Białe idą w górę, czarne w dół

    // Ruch o 1 pole do przodu
    if (board.isEmpty(x, y + direction)) {
        moves.push_back({x, y + direction});

        // Jeśli pionek jest na swojej pozycji startowej, może ruszyć się o 2 pola
        if ((isWhitePiece() && y == 6) || (!isWhitePiece() && y == 1)) {
            if (board.isEmpty(x, y + 2 * direction)) {
                moves.push_back({x, y + 2 * direction});
            }
        }
    }

    // Bicie po skosie
    for (int dx : {-1, 1}) {  // Lewy i prawy skos
        int newX = x + dx;
        int newY = y + direction;

        if (board.isEnemy(newX, newY, isWhitePiece())) {
            moves.push_back({newX, newY});
        }
    }

    // EN PASSANT
    if (board.getEnPassantTarget().has_value()) {  // Sprawdzamy, czy jest cel en passant
        auto [ex, ey] = board.getEnPassantTarget().value();

        if (ey == y + direction && (ex == x - 1 || ex == x + 1)) {
            moves.push_back({ex, ey});  // Możemy bić en passant!
        }
    }

    return moves;
}
