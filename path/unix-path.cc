#include "unix-path.hh"

std::string UnixPath::to_string() const
{
    std::string res = "/";
    size_t i = 0;
    if (this->path_.size() > 0)
    {
        for (; i < this->path_.size() - 1; i++)
        {
            res.append(path_[i]);
            res.push_back('/');
        }
        res.append(path_[i]);
        if (this->final_ == false)
        {
            res.push_back('/');
        }
    }
    return res;
}