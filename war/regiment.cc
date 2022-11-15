#include "regiment.hh"

Regiment::Regiment()
{}

void Regiment::join_by(Regiment& r)
{
    for (auto x : r.regiment_)
    {
        this->regiment_.push_back(x);
    }
    // this->regiment_.insert(this->regiment_.begin(), r.regiment_.begin(),
    //                        r.regiment_.end());
    size_t len = r.regiment_.size();
    for (size_t i = 0; i < len; i++)
    {
        r.regiment_.pop_back();
    }
}

size_t Regiment::count() const
{
    return this->regiment_.size();
}

void Regiment::add_soldier(Soldier* s)
{
    this->regiment_.push_back(s);
}

void Regiment::print_state() const
{
    for (auto var : this->regiment_)
    {
        var->print_state();
    }
}

void Regiment::scream() const
{
    for (auto var : this->regiment_)
    {
        var->scream();
    }
}