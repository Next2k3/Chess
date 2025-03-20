#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "../Piece.hpp"

class Knight : public Piece {
public:
    Knight(bool isWhite) : Piece(isWhite ? 'N' : 'n', isWhite) {}

    std::vector<std::pair<int,int>> getRawMoves(int x, int y, const Board& board) const override;
};

#endif