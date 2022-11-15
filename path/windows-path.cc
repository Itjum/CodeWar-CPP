#include "windows-path.hh"

WindowsPath::WindowsPath(char drive)
    : drive_(drive)
{}

std::string WindowsPath::to_string() const
{
    std::string res = "";
    res.push_back(this->drive_);
    res.push_back(':');
    res.push_back('\\');
    size_t i = 0;
    if (this->path_.size() > 0)
    {
        for (; i < this->path_.size() - 1; i++)
        {
            res.append(path_[i]);
            res.push_back('\\');
        }
        res.append(path_[i]);
        if (this->final_ == false)
        {
            res.push_back('\\');
        }
    }
    return res;
}

Path& WindowsPath::join(const std::string& tail, bool is_file)
{
    bool check = false;
    for (size_t i = 0; i < tail.size() && check == false; i++)
    {
        if (tail[i] == ':' || tail[i] == '"' || tail[i] == '|' || tail[i] == '?'
            || tail[i] == '*')
            check = true;
    }
    if (final_ == false && check == false)
    {
        if (is_file == true)
            final_ = true;
        this->path_.push_back(tail);
        return *this;
    }
    else
        return *this;
}