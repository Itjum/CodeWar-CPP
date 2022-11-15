#pragma once

#include <vector>
template <class T>
bool palindrome(std::vector<T> vec)
{
    int j = vec.size() - 1;
    for (size_t i = 0; i < vec.size() / 2; i++)
    {
        if (vec.at(i) != vec.at(j))
        {
            return false;
        }
        j--;
    }
    return true;
}