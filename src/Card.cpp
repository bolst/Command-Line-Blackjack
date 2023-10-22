#include "Card.h"

Card::Card(Face face, Suit suit) : _face(face), _suit(suit){};

Face Card::face() const { return _face; }
Suit Card::suit() const { return _suit; }

int Card::face_value() const
{
    switch (_face)
    {
    case Face::ACE:
        return 1;
    case Face::TWO:
        return 2;
    case Face::THREE:
        return 3;
    case Face::FOUR:
        return 4;
    case Face::FIVE:
        return 5;
    case Face::SIX:
        return 6;
    case Face::SEVEN:
        return 7;
    case Face::EIGHT:
        return 8;
    case Face::NINE:
        return 9;
    case Face::TEN:
    case Face::JACK:
    case Face::QUEEN:
    case Face::KING:
        return 10;
    default:
        return 0;
    }
}

bool Card::equals(const Card &other)
{
    return this->face_value() == other.face_value();
}

bool operator==(const Card &lhs, const Card &rhs)
{
    return lhs.suit() == rhs.suit() && lhs.face() == rhs.face();
}
std::ostream &operator<<(std::ostream &os, const Card &card)
{
    switch (card.face())
    {
    case Face::ACE:
        os.put('A');
        break;
    case Face::TWO:
        os.put('2');
        break;
    case Face::THREE:
        os.put('3');
        break;
    case Face::FOUR:
        os.put('4');
        break;
    case Face::FIVE:
        os.put('5');
        break;
    case Face::SIX:
        os.put('6');
        break;
    case Face::SEVEN:
        os.put('7');
        break;
    case Face::EIGHT:
        os.put('8');
        break;
    case Face::NINE:
        os.put('9');
        break;
    case Face::TEN:
        os.put('1');
        os.put('0');
        break;
    case Face::JACK:
        os.put('J');
        break;
    case Face::QUEEN:
        os.put('Q');
        break;
    case Face::KING:
        os.put('K');
        break;
    default:
        break;
    }

    switch (card.suit())
    {
    case Suit::SPADES:
        os.put('S');
        break;
    case Suit::CLUBS:
        os.put('C');
        break;
    case Suit::HEARTS:
        os.put('H');
        break;
    case Suit::DIAMONDS:
        os.put('D');
        break;
    default:
        break;
    }

    return os;
}
