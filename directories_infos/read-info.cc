#include "read-info.hh"

#include <iostream>
#include <sstream>
#include <string>

#include "directory-info.hh"

DirectoryInfo* read_info(std::ifstream& file)
{
    std::string word;
    std::string name;
    unsigned int size;
    unsigned int rights;
    std::string owner;
    std::string testmore;

    if (!file.is_open())
    {
        return nullptr;
    }

    std::string l;
    if (std::getline(file, l))
    {
        std::stringstream strs(l);
        strs >> name;
        if (name == "" || name.size() == 0)
        {
            return nullptr;
        }
        strs >> size;
        strs >> std::oct >> rights;
        strs >> owner;
        if (owner.size() == 0 || owner == "")
        {
            return nullptr;
        }
        strs >> testmore;
        if (testmore.size() != 0 || testmore != "")
        {
            return nullptr;
        }
        return new DirectoryInfo(name, size, rights, owner);
    }
    return nullptr;
}