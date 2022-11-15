#pragma once

#include <iostream>
#include <string>

class Soldier
{
public:
    Soldier(int health = 15, int damage = 3,
            std::string scream = "No pity for losers!");

    void attack(Soldier& s);
    void print_state() const;
    void scream() const;

    int health_;
    int damage_;
    std::string scream_;
};
