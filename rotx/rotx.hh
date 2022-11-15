#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

#include "encrypt.hh"

class RotX : public Encrypt
{
public:
    RotX(std::string input, int key)
        : Encrypt(input)
        , key_(key)
    {}
    void process() override;

private:
    int key_;
};
