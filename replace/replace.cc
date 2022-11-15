#include "replace.hh"

#include <fstream>
#include <iostream>
#include <string>

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::ifstream file_in;
    std::ofstream file_out;
    std::string line;
    std::string token;
    size_t len = src_token.length();

    file_in.open(input_filename);
    if (!file_in.is_open())
    {
        std::cerr << "Cannot open input file" << '\n';
        return;
    }

    file_out.open(output_filename);
    if (!file_out.is_open())
    {
        std::cerr << "Cannot write output file" << '\n';
        return;
    }

    while (std::getline(file_in, line))
    {
        if (!file_in)
        {
            break;
        }
        size_t index = line.find(src_token);
        if (index != std::string::npos)
        {
            while (index < line.size())
            {
                line.replace(index, len, dst_token);
                index += dst_token.size();
                index = line.find(src_token, index);
            }
        }
        file_out << line << "\n";
    }
}