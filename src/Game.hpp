#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"

class Game {
private:
    Board board;
    bool isWhiteTurn;
public:
    Game();
    void play();
};

#endif