#include "game.hh"

#include <iostream>

void Game::play(Player& p1, Player& p2)
{
    if (std::addressof(p1) == std::addressof(p2))
    {
        throw InvalidArgumentException("Stop playing by yourself!");
    }
}