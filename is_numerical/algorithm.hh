#pragma once

#include "enable-if.hh"
#include "is-numerical.hh"

template <typename T,
          typename U = typename enable_if<is_numerical<T>::value, T>::type>
void algorithm(T)
{}