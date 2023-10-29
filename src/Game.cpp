#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <utility>

void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}

Game::Game() {}

Game::~Game() {}

void sleep(const int sec)
{
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}

std::vector<Player> get_players()
{
    // TODO: get players

    std::cin.ignore();

    std::vector<Player> retval;
    retval.emplace_back(Player("Nic", 1));
    retval.emplace_back(Player("Chris", 2));
    retval.emplace_back(Player("Steve", 3));
    std::cout << "Players:\n";
    for (auto &player : retval)
        std::cout << player << '\n';

    return retval;
}

void Game::run()
{
    clear_screen();

    std::cout << "Welcome to Blackjack!\n\n";
    sleep(1);

    std::cout << "Waiting for players...\n";
    std::vector<Player> players = get_players();
    GameManager gm(Player("Dealer", 0), players);
    std::cout << "Starting game!\n";
    sleep(1);

    std::cout << "Shuffling cards...\n";
    gm.shuffle_deck();
    sleep(1);

    std::cout << "Dealing cards...\n";
    gm.deal_cards();
    gm.print_hands();
    sleep(1);
}
