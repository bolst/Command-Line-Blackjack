#include "GameManager.h"
#include <iostream>
#include <random>
#include <algorithm>

GameManager::GameManager(){};

GameManager::GameManager(Player dealer, std::vector<Player> &players)
{
    _dealer = std::make_unique<Player>(Player(dealer.name(), dealer.id()));
    for (Player player : players)
    {
        _players.push_back(std::make_unique<Player>(Player(player.name(), player.id())));
    }
}

void GameManager::add_player(const Player player)
{
    _players.push_back(std::make_unique<Player>(Player(player.name(), player.id())));
}

void GameManager::set_dealer(const Player dealer)
{
    _dealer = std::make_unique<Player>(Player(dealer.name(), dealer.id()));
}

bool GameManager::remove_player(const int player_id)
{
    for (auto it = _players.begin(); it != _players.end(); ++it)
    {
        if ((*it)->id() == player_id)
        {
            _players.erase(it);
            return true;
        }
    }
    return false;
}

void GameManager::deal_cards(const int num_cards)
{
    if (num_cards * (_players.size() + 1) > deck.size())
    {
        std::cout << "Not enough cards in deck to deal " << num_cards << " cards.\n";
        return;
    }

    for (int i = 0; i < num_cards; ++i)
    {
        for (auto it = _players.begin(); it != _players.end(); ++it)
        {
            (*it)->hands[0].add_card(deck.top_card());
            deck.pop_card(deck.top_card());
        }

        _dealer->hands[0].add_card(deck.top_card());
        deck.pop_card(deck.top_card());
    }
}

void GameManager::return_player_cards()
{
    for (auto it = _players.begin(); it != _players.end(); ++it)
    {
        for (Hand hand : (*it)->hands)
        {
            for (Card card : hand.cards())
            {
                deck.add_card(hand.top_card());
                hand.pop_card(hand.top_card());
            }
        }
    }
}

void GameManager::shuffle_deck()
{
    deck.shuffle();
}

void GameManager::print_players() const
{
    for (auto it = _players.begin(); it != _players.end(); ++it)
    {
        std::cout << *(*it) << '\n';
    }
}

void GameManager::print_dealer() const
{
    std::cout << *_dealer << '\n';
}

void GameManager::print_deck() const
{
    std::cout << deck << '\n';
}

void GameManager::print_hands() const
{
    std::cout << "Dealer hand: " << _dealer->hands << '\n';
    for (auto it = _players.begin(); it != _players.end(); ++it)
    {
        std::cout << (*it)->name() << ": " << (*it)->hands << '\n';
    }
}