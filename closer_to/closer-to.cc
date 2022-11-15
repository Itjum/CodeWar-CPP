#include "closer-to.hh"

#include <iostream>

CloserTo::CloserTo(int i)
    : i_(i)
{}

bool CloserTo::operator()(const int& a, const int& b) const
{
    auto temp1 = std::abs(a - i_);
    auto temp2 = std::abs(b - i_);
    if (temp1 == temp2)
    {
        if (a < b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return (temp1 <= temp2) ? true : false;
}