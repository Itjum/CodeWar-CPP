#pragma once

#include <iostream>
#include <string>

class WordChecker
{
public:
    WordChecker(std::string path);

    bool operator()(const std::string word);

private:
    std::string path_;
};