#pragma once

#include "bimap.hh"

template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T1& v1, const T2& v2)
{
    lhs.insert({ v1, v2 });
    rhs.insert({ v2, v1 });
}

template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T2& v1, const T1& v2)
{
    lhs.insert({ v2, v1 });
    rhs.insert({ v1, v2 });
}

template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T1& v)
{
    auto i = lhs.find(v);
    if (i != lhs.end())
    {
        rhs.erase(i->second);
        lhs.erase(i);
    }
}

template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T2& v)
{
    auto i = rhs.find(v);
    if (i != rhs.end())
    {
        lhs.erase(i->second);
        rhs.erase(i);
    }
}

template <typename T1, typename T2>
void Bimap<T1, T2>::clear()
{
    this->lhs.clear();
    this->rhs.clear();
}

template <typename T1, typename T2>
std::size_t Bimap<T1, T2>::size() const
{
    return this->lhs.size();
}

template <typename T1, typename T2>
typename Bimap<T1, T2>::iteratorT1 Bimap<T1, T2>::find(const T1& v)
{
    return lhs.find(v);
}

template <typename T1, typename T2>
typename Bimap<T1, T2>::iteratorT2 Bimap<T1, T2>::find(const T2& v)
{
    return rhs.find(v);
}
