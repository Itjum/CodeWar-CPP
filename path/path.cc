#include "path.hh"

Path& Path::join(const std::string& tail, bool is_file)
{
    if (final_ == false)
    {
        if (is_file == true)
            final_ = true;
        this->path_.push_back(tail);
        return *this;
    }
    else
        return *this;
}