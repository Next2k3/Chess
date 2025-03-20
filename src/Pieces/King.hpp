#ifndef KING_HPP
#define KING_HPP

#include "../Piece.hpp"

class King : public Piece {
public:
    King(bool isWhite) : Piece(isWhite ? 'K' : 'k', isWhite) {}

    std::vector<std::pair<int,int>> getRawMoves(int x, int y, const Board& board) const override;
};

#endif