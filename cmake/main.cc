#include <iostream>

#include "libhello/hello.hh"

int main(int argc, const char** argv)
{
    if (argc <= 1)
    {
        std::cout << "Usage: /student <name>\n";
        return 1;
    }
    else
    {
        std::cout << "Hello " << argv[1] << "!\n";
    }
    return 0;
}
