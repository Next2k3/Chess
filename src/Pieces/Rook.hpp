#ifndef ROOK_HPP
#define ROOK_HPP

#include "../Piece.hpp"

class Rook : public Piece {
public:
    Rook(bool isWhite) : Piece(isWhite ? 'R' : 'r', isWhite) {}

    std::vector<std::pair<int,int>> getRawMoves(int x, int y, const Board& board) const override;
};

#endif