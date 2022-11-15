#include "termcolor.hh"

#include <ostream>

namespace termcolor
{
    my_ostream::my_ostream(my_ostream& ost)
        : copyverif(false)
        , my_ostr(ost.my_get())
    {
        ost.set_copy_verif();
    }

    my_ostream::my_ostream(std::ostream& out)
        : copyverif(false)
        , my_ostr(out)
    {}

    my_ostream::~my_ostream()
    {
        if (copyverif == false)
        {
            std::ostream& out = my_get();
            out << "\x1B[0m";
        }
    }

    void my_ostream::set_copy_verif()
    {
        this->copyverif = true;
    }

    std::ostream& my_ostream::my_get()
    {
        return this->my_ostr;
    }

    my_ostream operator<<(std::ostream& out, background value)
    {
        auto res = my_ostream(out);
        res.my_get() << "\x1B[" << static_cast<int>(value) << "m";
        return res;
    }

    my_ostream operator<<(std::ostream& out, foreground value)
    {
        auto res = my_ostream(out);
        res.my_get() << "\x1B[" << static_cast<int>(value) << "m";
        return res;
    }

    my_ostream operator<<(my_ostream input, foreground value)
    {
        input.my_get() << "\x1B[" << static_cast<int>(value) << "m";
        return input;
    }

    my_ostream my_ostream::operator<<(std::ostream& (*func)(std::ostream&))
    {
        this->my_get() << func;
        return *this;
    }

} // namespace termcolor