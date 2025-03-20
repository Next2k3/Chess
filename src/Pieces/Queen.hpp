#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "../Piece.hpp"

class Queen : public Piece {
public:
    Queen(bool isWhite) : Piece(isWhite ? 'Q' : 'q', isWhite) {}

    std::vector<std::pair<int,int>> getRawMoves(int x, int y, const Board& board) const override;
};

#endif