#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "../Piece.hpp"

class Bishop : public Piece {
public:
    Bishop(bool isWhite) : Piece(isWhite ? 'B' : 'b', isWhite) {}

    std::vector<std::pair<int, int>> getRawMoves(int x, int y, const Board& board) const override;
};

#endif