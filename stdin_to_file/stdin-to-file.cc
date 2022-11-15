#include "stdin-to-file.hh"

#include <iostream>

void stdin_to_file()
{
    std::ofstream file_out;
    file_out.open("file.out");
    if (file_out.is_open())
    {
        // std::cout << "Output file is open.\n";
    }
    else
    {
        return;
        std::cout << "Output file isn't open.\n";
    }
    std::string input;
    std::string word;
    while (std::cin >> input)
    {
        file_out << input << "\n";
    }
}