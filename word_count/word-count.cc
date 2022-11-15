#include "word-count.hh"

#include <fstream>
#include <iostream>

ssize_t word_count(const std::string& filename)
{
    ssize_t res = 0;
    std::ifstream file_in;
    std::string token;
    file_in.open(filename);
    if (file_in.is_open())
    {
        std::string line;
        while (file_in >> token)
        {
            res++;
        }
    }
    else
    {
        return -1;
    }
    return res;
}