#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Piece.hpp"
#include "Pieces/Pawn.hpp"
#include <optional>

class Board {
private:
    std::vector<std::vector<Piece*>> grid;
    std::optional<std::pair<int,int>> enPassantTarget;
public:
    Board();
    ~Board();

    void display() const;
    Piece* getPiece(int x, int y) const;
    void movePiece(int startX, int startY, int endX, int endY);

    bool isEmpty(int x, int y) const;
    bool isEnemy(int x, int y, bool isWhite) const;

    std::vector<std::pair<int,int>> getLegalMoves(int x,int y);
    bool isCheck(bool isWhite) const;

    std::optional<std::pair<int,int>> getEnPassantTarget() const { return enPassantTarget; }
    void setEnPassantTarget(std::optional<std::pair<int, int>> target) { enPassantTarget = target; }
};

#endif