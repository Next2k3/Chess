#include "Rook.hpp"
#include "../Board.hpp"

std::vector<std::pair<int,int>> Rook::getRawMoves(int x, int y, const Board& board) const {
    std::vector<std::pair<int,int>> moves;

    int directions[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};

    for (auto& dir : directions){
        int newX = x + dir[0];
        int newY = y + dir[1];

        while(board.isEmpty(newX, newY) || board.isEnemy(newX, newY, isWhitePiece())){
            moves.push_back({newX,newY});

            if (board.isEnemy(newX, newY, isWhitePiece())){
                break;
            }
            
            newX += dir[0];
            newY += dir[1];
        }
    }
    return moves;
}