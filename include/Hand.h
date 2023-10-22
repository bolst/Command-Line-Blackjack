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

    int value() const;
};