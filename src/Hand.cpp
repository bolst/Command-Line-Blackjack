#include "Hand.h"
#include "Card.h"
#include <algorithm>
#include <random>

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

Card Hand::top_card() const
{
    return _cards.back();
}

void Hand::shuffle()
{
    auto rd = std::random_device{};
    auto rng = std::default_random_engine{rd()};
    std::shuffle(std::begin(_cards), std::end(_cards), rng);
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

int Hand::size() const
{
    return _cards.size();
}

std::vector<Card> Hand::cards() const
{
    return _cards;
}

std::ostream &operator<<(std::ostream &os, const Hand &hand)
{
    for (auto card : hand.cards())
    {
        os << card << ' ';
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<Hand> &hands)
{
    for (auto hand : hands)
        os << hand << ' ';
    return os;
}

Hand generate_full_deck()
{
    Hand deck;
    for (auto suit : SUITS)
    {
        for (auto face : FACES)
        {
            deck.add_card(Card(face, suit));
        }
    }
    return deck;
}
