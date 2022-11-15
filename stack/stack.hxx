#pragma once

#include <ostream>
#include <stdexcept>

#include "stack.hh"

template <class T>
Stack<T>::Stack(size_t max_size)
    : elements_()
    , max_size_(max_size)
{
    try
    {
        elements_.reserve(max_size);
    }
    catch (const std::length_error& e)
    {
        throw StackCreationFailed("Max stack size is too big.");
    }
    catch (const std::bad_alloc& e)
    {
        throw StackCreationFailed("Allocation failed.");
    }
}

template <class T>
Stack<T>& Stack<T>::push(const T& item)
{
    if (this->elements_.size() == this->max_size_)
    {
        throw StackMaxSize("Unable to push, stack max size reached.");
    }
    this->elements_.push_back(item);
    return *this;
}

template <class T>
T Stack<T>::operator--()
{
    return this->pop();
}

template <class T>
T Stack<T>::pop()
{
    if (elements_.size() == 0)
    {
        throw StackEmpty("Unable to pop, stack is empty.");
    }
    T res = this->elements_[this->elements_.size() - 1];
    this->elements_.pop_back();
    return res;
}

template <class T>
typename Stack<T>::iterator Stack<T>::begin()
{
    return elements_.rbegin();
}

template <class T>
typename Stack<T>::const_iterator Stack<T>::begin() const
{
    return elements_.crbegin();
}

template <class T>
typename Stack<T>::iterator Stack<T>::end()
{
    return elements_.rend();
}

template <class T>
typename Stack<T>::const_iterator Stack<T>::end() const
{
    return elements_.crend();
}

template <class T>
void Stack<T>::resize(size_t t)
{
    if (t < this->max_size() && t < this->elements_.size())
    {
        while (this->elements_.size() != t)
        {
            this->elements_.pop_back();
        }
    }
    try
    {
        this->max_size_ = t;
        this->elements_.reserve(t);
    }
    catch (const std::length_error& e)
    {
        throw StackCreationFailed("Max stack size is too big.");
    }
    catch (const std::bad_alloc& e)
    {
        throw StackCreationFailed("Allocation failed.");
    }
}

template <class T>
size_t Stack<T>::max_size() const
{
    return this->max_size_;
}

template <class T>
T Stack<T>::operator[](size_t i)
{
    if (i >= this->elements_.size())
    {
        throw std::out_of_range("Out of range.");
    }
    return this->elements_[this->elements_.size() - i - 1];
}

template <class T>
Stack<T>& Stack<T>::operator+=(const T& item)
{
    return push(item);
}

template <class T>
Stack<T>& Stack<T>::operator<<(const T& item)
{
    return push(item);
}

template <class T>
bool Stack<T>::operator==(Stack<T> b)
{
    if (this->max_size() != b.max_size())
    {
        return false;
    }
    for (size_t i = 0; i < this->elements_.size(); i++)
    {
        if (this->elements_[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

template <class T>
std::ostream& Stack<T>::print(std::ostream& s) const
{
    if (this->elements_.size() >= 1)
    {
        s << elements_[0];
        for (size_t i = 1; i < this->elements_.size(); i++)
        {
            s << ' ' << elements_[i];
        }
    }
    return s;
}
