#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <vector>

enum class Face
{
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

enum class Suit
{
    SPADES,
    CLUBS,
    HEARTS,
    DIAMONDS
};

extern const std::vector<Face> FACES;
extern const std::vector<Suit> SUITS;

class Card
{
private:
    Face _face;
    Suit _suit;

public:
    Card() = delete;
    Card(Face face, Suit suit);

    Face face() const;
    Suit suit() const;

    int face_value() const;

    bool equals(const Card &other);
};

bool operator==(const Card &lhs, const Card &rhs);
std::ostream &operator<<(std::ostream &os, const Card &card);
#endif