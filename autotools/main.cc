#include "libhello/hello.hh"

int main(int argc, const char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <name>\n";
        return 1;
    }
    say_hello(argv[1]);
    return 0;
}
