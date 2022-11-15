#pragma once

#include <iostream>
#include <memory>
#include <ostream>
#include <string>

namespace termcolor
{
    enum class background : unsigned int
    {
        black = 40,
        red = 41,
        green = 42,
        yellow = 43,
        blue = 44,
        magenta = 45,
        cyan = 46,
        white = 47
    };

    enum class foreground : unsigned int
    {
        black = 30,
        red = 31,
        green = 32,
        yellow = 33,
        blue = 34,
        magenta = 35,
        cyan = 36,
        white = 37
    };

    class my_ostream
    {
    public:
        my_ostream(std::ostream& out);
        my_ostream(my_ostream& ost);
        ~my_ostream();

        std::ostream& my_get();
        void set_copy_verif();
        template <class T>
        my_ostream operator<<(T input)
        {
            this->my_ostr << input;
            return *this;
        }
        my_ostream operator<<(std::ostream& (*func)(std::ostream&));

        bool copyverif;

    private:
        std::ostream& my_ostr;
    };

    my_ostream operator<<(std::ostream& out, background value);
    my_ostream operator<<(std::ostream& out, foreground value);
    my_ostream operator<<(my_ostream input, foreground value);

} // namespace termcolor
