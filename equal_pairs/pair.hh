#pragma once

template <typename T1, typename T2>
class Pair
{
public:
    /// Build the pair (v1, v2)
    Pair(T1 v1, T2 v2)
        : v1_(v1)
        , v2_(v2)
    {}

    /// Returns the first value
    T1& first()
    {
        return v1_;
    }
    const T1& first() const
    {
        return v1_;
    }

    /// Returns the second  value;
    T2& second()
    {
        return v2_;
    }
    const T2& second() const
    {
        return v2_;
    }

    /* FIXME: implement operator== */
    bool operator==(Pair<T1, T2> other);
    /* FIXME: implement operator!= */
    bool operator!=(Pair<T1, T2> other);

private:
    /// The first value
    T1 v1_;
    /// The second value
    T2 v2_;
};

template <class T1, class T2>
bool Pair<T1, T2>::operator==(Pair<T1, T2> other)
{
    if (this->first() == other.first())
    {
        if (this->second() == other.second())
            return true;
    }
    return false;
}

template <class T1, class T2>
bool Pair<T1, T2>::operator!=(Pair<T1, T2> other)
{
    if (this->first() != other.first() || this->second() != other.second())
    {
        return true;
    }
    return false;
}
