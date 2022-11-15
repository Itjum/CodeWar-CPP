#pragma once

#include <iostream>
#include <string>

class Encrypt
{
public:
    Encrypt(const std::string& input)
        : input_(input)
    {}
    // FIXME: Some code was deleted here.

    virtual void process() = 0;

protected:
    std::string input_;
};