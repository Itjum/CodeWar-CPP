#include "int-container.hh"

#include <iostream>
#include <memory>
#include <new>

MyIntContainer::MyIntContainer(size_t size)
    : current_size_(0)
    , max_size_(size)
    , elems_(std::make_unique<int[]>(size))
{}

void MyIntContainer::print() const
{
    if (get_len() > 1)
    {
        std::cout << elems_[0];
        for (size_t i = 1; i < get_len(); i++)
        {
            std::cout << " | " << elems_[i];
        }
        std::cout << '\n';
    }
    else if (get_len() == 1)
    {
        std::cout << elems_[0] << '\n';
    }
}

size_t MyIntContainer::get_len() const
{
    return current_size_;
}

bool MyIntContainer::add(int elem)
{
    if (get_len() >= max_size_)
    {
        return false;
    }
    elems_[current_size_] = elem;
    ++current_size_;
    return true;
}

std::optional<int> MyIntContainer::pop()
{
    if (get_len() > 0)
    {
        std::optional<int> res = elems_[current_size_ - 1];
        current_size_ -= 1;
        return res;
    }
    else
    {
        return std::nullopt;
    }
}

std::optional<int> MyIntContainer::get(size_t position) const
{
    if (position < get_len())
    {
        return elems_[position];
    }
    else
    {
        return std::nullopt;
    }
}

std::optional<size_t> MyIntContainer::find(int elem) const
{
    if (current_size_ > 0)
    {
        for (size_t i = 0; i < get_len(); i++)
        {
            if (elem == elems_[i])
            {
                return i;
            }
        }
    }
    return std::nullopt;
}

void MyIntContainer::sort()
{
    if (current_size_ > 1)
    {
        for (size_t i = 0; i < get_len(); i++)
        {
            for (size_t j = i; j < get_len(); j++)
            {
                if (elems_[i] > elems_[j])
                {
                    int temp = elems_[i];
                    elems_[i] = elems_[j];
                    elems_[j] = temp;
                }
            }
        }
    }
}

bool MyIntContainer::is_sorted() const
{
    if (current_size_ > 1)
    {
        for (size_t i = 0; i < get_len() - 1; i++)
        {
            if (elems_[i] > elems_[i + 1])
            {
                return false;
            }
        }
    }
    return true;
}