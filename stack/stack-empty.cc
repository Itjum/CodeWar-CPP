#include "stack-empty.hh"

#include <iostream>
#include <stdexcept>

StackEmpty::StackEmpty(const std::string& msg)
    : msg_(msg)
{}

const char* StackEmpty::what() const noexcept
{
    return msg_.c_str();
}