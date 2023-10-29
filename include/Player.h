#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include <string>
#include <iostream>

class Player
{
private:
    std::string _name;
    int _id;

public:
    std::vector<Hand> hands;

    Player();
    Player(const std::string &name, int id);

    std::string name() const;
    int id() const;
};

std::ostream &operator<<(std::ostream &os, const Player &player);

#endif // PLAYER_H