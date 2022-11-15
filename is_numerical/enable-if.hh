#pragma once

template <bool B, class N = void>
struct enable_if
{};

template <class N>
struct enable_if<true, N>
{
    typedef N type;
};
