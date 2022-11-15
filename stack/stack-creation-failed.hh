#pragma once

#include <exception>
#include <stdexcept>
#include <string>

class StackCreationFailed : public std::exception
{
public:
    StackCreationFailed(const std::string& msg);

    virtual const char* what() const noexcept;

private:
    std::string msg_;
};