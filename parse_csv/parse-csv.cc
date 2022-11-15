#include "parse-csv.hh"

#include <fstream>
#include <ios>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> parse_csv(const std::string& file_name)
{
    std::ifstream file;
    file.open(file_name);
    if (!file.is_open())
    {
        throw std::ios_base::failure("Error opening file");
    }
    else
    {
        std::vector<std::vector<std::string>> res;
        std::string line;
        size_t colcount = 0;
        size_t countLine = 0;
        while (std::getline(file, line))
        {
            ++countLine;
            size_t currentcolcount = 0;
            size_t countcommas = 0;
            size_t i = 0;
            while (i < line.size())
            {
                if (line[i] == ',')
                {
                    ++currentcolcount;
                }
                if (line[i] == ',' && i == line.size() - 1)
                {
                    ++countcommas;
                }
                i++;
            }
            std::string word;
            std::stringstream ss(line);
            std::vector<std::string> words;
            while (std::getline(ss, word, ','))
            {
                words.push_back(word);
            }

            if (colcount == 0)
                colcount = currentcolcount;

            if (currentcolcount != colcount)
            {
                std::string temp = "Non consistent number of columns at line "
                    + std::to_string(countLine);
                throw std::ios_base::failure(temp);
            }

            while (countcommas > 0)
            {
                words.push_back("");
                --countcommas;
            }
            res.push_back(words);
        }
        return res;
    }
}