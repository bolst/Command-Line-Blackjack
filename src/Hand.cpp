#include "Hand.h"
#include "Card.h"
#include <algorithm>

Hand::Hand() {}

Hand::Hand(const Card &card)
{
    _cards.push_back(card);
}

Hand::Hand(const Card &card1, const Card &card2)
{
    _cards.push_back(card1);
    _cards.push_back(card2);
}

void Hand::add_card(const Card &card)
{
    _cards.push_back(card);
}

bool Hand::pop_card(const Card &card_to_remove)
{
    auto it = std::find(_cards.begin(), _cards.end(), card_to_remove);
    if (it != _cards.end())
    {
        _cards.erase(it);
        return true;
    }
    return false;
}

int Hand::value() const
{
    int value = 0;
    for (auto card : _cards)
    {
        value += card.face_value();
    }
    return value;
}