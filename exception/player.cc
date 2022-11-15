#include "player.hh"

#include <iostream>
#include <stdexcept>

Player::Player(const std::string& name, unsigned int age)
    : name_(name)
    , age_(age)
{
    if (name == "")
    {
        throw InvalidArgumentException("Name can't be empty.");
    }
    else if (age > 150)
    {
        throw InvalidArgumentException("Sorry gramp, too old to play.");
    }
}
