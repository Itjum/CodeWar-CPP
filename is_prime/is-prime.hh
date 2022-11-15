#pragma once

template <unsigned N>
constexpr bool is_prime()
{
    for (unsigned i = 2; i <= N / 2; i++)
    {
        if (N % i == 0)
        {
            return false;
        }
    }
    return true;
}

template <>
constexpr bool is_prime<1>()
{
    return false;
}

template <>
constexpr bool is_prime<0>()
{
    return false;
}