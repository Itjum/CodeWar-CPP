#pragma once

#include <string>

#include "soldier.hh"

class Assassin : public Soldier
{
public:
    Assassin();
    int health_;
    int damage_;
    std::string scream_;
};