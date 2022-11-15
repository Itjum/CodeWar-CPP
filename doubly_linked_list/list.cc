#include "list.hh"

#include <memory>

List::List()
    : nb_elts_(0)
    , first_()
    , last_()
{}

void List::push_front(int i)
{
    auto newNode = std::make_shared<Node>(i);
    newNode->prev_set(nullptr);
    if (first_ != nullptr)
    {
        first_->prev_set(newNode);
    }
    if (last_ == nullptr)
    {
        last_ = newNode;
    }
    newNode->next_set(first_);
    first_ = newNode;
    nb_elts_ += 1;
}

void List::push_back(int i)
{
    auto newNode = std::make_shared<Node>(i);
    newNode->next_set(nullptr);
    if (last_ != nullptr)
    {
        last_->next_set(newNode);
    }
    if (first_ == nullptr)
    {
        first_ = newNode;
    }
    newNode->prev_set(last_);
    last_ = newNode;
    this->nb_elts_ += 1;
}

std::optional<int> List::pop_front()
{
    if (length() > 0)
    {
        auto res = first_->val_get();
        auto curfirst = this->first_;
        auto next = this->first_->next_get();
        if (next != nullptr)
        {
            next->prev_set(nullptr);
        }
        curfirst->next_set(nullptr);
        this->first_ = next;
        this->nb_elts_ -= 1;
        return res;
    }
    else
    {
        return std::nullopt;
    }
}

std::optional<int> List::pop_back()
{
    if (length() > 0)
    {
        auto prev = this->last_->prev_get();
        auto l = this->last_;
        auto res = l->val_get();
        if (prev != nullptr)
        {
            prev->next_set(nullptr);
        }
        l->prev_set(nullptr);
        this->last_ = prev;
        if (length() == 1)
        {
            this->first_ = prev;
        }
        this->nb_elts_ -= 1;
        return res;
    }
    else
    {
        return std::nullopt;
    }
}

void List::print(std::ostream& os) const
{
    if (this->length() >= 1)
    {
        auto temp = this->first_;
        os << temp->val_get();
        while (temp->next_get() != nullptr)
        {
            temp = temp->next_get();
            os << ' ' << temp->val_get();
        }
    }
}

int List::length() const
{
    return this->nb_elts_;
}