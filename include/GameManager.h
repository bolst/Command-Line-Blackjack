#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Player.h"
#include <vector>
#include <memory>

class GameManager
{
private:
    std::shared_ptr<Player> _dealer;
    std::vector<std::shared_ptr<Player>> _players;
    Hand deck = generate_full_deck();

public:
    GameManager();
    GameManager(Player dealer, std::vector<Player> &players);

    void add_player(const Player player);
    void set_dealer(const Player dealer);
    bool remove_player(const int player_id);

    void deal_cards(const int num_cards = 2);

    void return_player_cards();

    void shuffle_deck();

    void print_players() const;
    void print_dealer() const;
    void print_deck() const;
    void print_hands() const;
};

#endif // GAME_MANAGER_H