#include "engine.hh"

#include <iostream>

Engine::Engine(int fuel)
{
    fuel_ = fuel;
}

bool Engine::start()
{
    if (fuel_ >= 1)
    {
        this->fuel_ -= 1;
        std::cout << "Engine starts with " << fuel_ << " units of fuel" << '\n';
        return true;
    }
    else
    {
        return false;
    }
}

void Engine::use(int consumed)
{
    if (consumed >= fuel_)
    {
        std::cout << "Engine uses " << fuel_ << " fuel units" << '\n';
        fuel_ = 0;
    }
    else
    {
        fuel_ = fuel_ - consumed;
        std::cout << "Engine uses " << consumed << " fuel units" << '\n';
    }
}

void Engine::stop() const
{
    std::cout << "Stop Engine" << '\n';
}

void Engine::fill(int fuel)
{
    this->fuel_ += fuel;
    std::cout << "Engine now has " << fuel_ << " fuel units" << '\n';
}