#ifndef GAME_H
#define GAME_H

#include "GameManager.h"

class Game
{
private:
    GameManager gameManager;

public:
    Game();
    ~Game();

    void run();
};

#endif // GAME_H