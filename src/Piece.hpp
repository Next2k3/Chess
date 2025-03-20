#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>
#include <utility>

class Board;

class Piece {
protected:
    char symbol;  // 'P', 'N', 'B', 'R', 'Q', 'K' (dla białych), 'p', 'n'... (dla czarnych)
    bool isWhite;
public:
    Piece(char symbol, bool isWhite) : symbol(symbol), isWhite(isWhite) {}
    virtual ~Piece() = default;

    virtual std::vector<std::pair<int, int>> getRawMoves(int x,int y,const Board &board) const = 0;
    char getSymbol() const { return symbol; }
    bool isWhitePiece() const { return isWhite; }
};

#endif