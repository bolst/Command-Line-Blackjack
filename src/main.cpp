#include <iostream>
#include "Card.h"
#include "Game.h"

int main()
{
    std::cout << "Hello world!\n";
    Game *game = new Game();
    game->run();
}