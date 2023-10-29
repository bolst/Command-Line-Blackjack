#include "Player.h"

Player::Player() : _name("unnamed"), _id(-1) {}

Player::Player(const std::string &name, int id) : _name(name), _id(id)
{
    hands.push_back(Hand());
}

std::string Player::name() const
{
    return _name;
}

int Player::id() const
{
    return _id;
}

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    os << player.name() << " (" << player.id() << ")";
    return os;
}