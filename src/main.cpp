#include <iostream>
#include "Card.h"

int main()
{
    Card card(Face::ACE, Suit::SPADES);
    std::cout << card << '\n';
}