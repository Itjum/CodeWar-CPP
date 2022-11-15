#include "forward-multiplication.hh"

lambda_type create_lambda()
{
    auto res = [](int x) { return [=](int y) { return x * y; }; };
    return res;
}