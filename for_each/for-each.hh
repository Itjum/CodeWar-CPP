#pragma once

template <class T, class F>
void my_foreach(T a, T b, F f)
{
    while (a != b)
    {
        f(*a);
        a++;
    }
}