#include "stack-max-size.hh"

#include <iostream>
#include <stdexcept>

StackMaxSize::StackMaxSize(const std::string& msg)
    : msg_(msg)
{}

const char* StackMaxSize::what() const noexcept
{
    return msg_.c_str();
}