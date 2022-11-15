#pragma once

#include <exception>
#include <stdexcept>
#include <string>

class StackEmpty : public std::exception
{
public:
    StackEmpty(const std::string& msg);

    virtual const char* what() const noexcept;

private:
    std::string msg_;
};