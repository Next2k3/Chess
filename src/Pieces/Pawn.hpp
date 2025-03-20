#ifndef PAWN_HPP
#define PAWN_HPP

#include "../Piece.hpp"
#include "../Board.hpp"

class Pawn : public Piece {
public:
    Pawn(bool isWhite) : Piece(isWhite ? 'P' : 'p', isWhite) {}

    std::vector<std::pair<int, int>> getRawMoves(int x, int y, const Board& board) const override;
};

#endif