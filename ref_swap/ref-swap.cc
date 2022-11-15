#include "ref-swap.hh"

#include <iostream>

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}