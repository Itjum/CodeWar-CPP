#include "word-checker.hh"

#include <fstream>
#include <string>
#include <vector>

WordChecker::WordChecker(std::string path)
    : path_(path)
{}

bool WordChecker::operator()(const std::string word)
{
    std::ifstream file_in;
    std::string token;

    std::vector<std::pair<char, char>> vec;
    std::pair<char, char> pair;
    bool res = true;

    for (size_t i = 1; i < word.size(); i++)
    {
        pair.first = word[i - 1];
        pair.second = word[i];
        vec.push_back(pair);
    }
    if (vec.size() == 0)
    {
        file_in.open(path_);
        while (file_in >> token)
        {
            if (token == word)
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        file_in.open(path_);
        for (size_t z = 0; z < vec.size() && res == true; z++)
        {
            bool temp = false;

            while (file_in >> token && temp == false)
            {
                for (size_t i = 1; i < token.size() && temp == false; i++)
                {
                    char t1 = token[i - 1];
                    char t2 = token[i];
                    if (t1 == vec[z].first && t2 == vec[z].second)
                    {
                        temp = true;
                    }
                }
            }
            file_in.clear();
            file_in.seekg(0, std::iostream::beg);
            if (temp == false)
                res = false;
        }
    }
    return res;
}