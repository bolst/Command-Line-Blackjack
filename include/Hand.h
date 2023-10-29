#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>

class Hand
{
private:
    std::vector<Card> _cards;

public:
    Hand();
    Hand(const Card &card);
    Hand(const Card &card1, const Card &card2);

    void add_card(const Card &card);
    bool pop_card(const Card &card_to_remove);
    Card top_card() const;

    void shuffle();

    int value() const;

    int size() const;

    std::vector<Card> cards() const;
};

Hand generate_full_deck();
std::ostream &operator<<(std::ostream &os, const Hand &hand);
std::ostream &operator<<(std::ostream &os, const std::vector<Hand> &hands);

#endif // HAND_H