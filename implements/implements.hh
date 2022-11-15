#pragma once

template <typename T, typename T2 = T>
concept impl_basic_op = requires(T x, T2 y)
{
    {
        (x + y)
        } -> std::convertible_to<T>;
    {
        (x * y)
        } -> std::convertible_to<T>;
    {
        (x - y)
        } -> std::convertible_to<T>;
    {
        (x / y)
        } -> std::convertible_to<T>;
    {
        (-x)
        } -> std::convertible_to<T>;
    {
        (-y)
        } -> std::convertible_to<T>;
    {
        (+x)
        } -> std::convertible_to<T>;
    {
        (+y)
        } -> std::convertible_to<T>;
};

template <typename T, typename T2 = T>
concept impl_modulo = requires(T x, T2 y)
{
    {
        (x % y)
        } -> std::convertible_to<T>;
};

template <typename T, typename T2 = T>
concept impl_bitwise_op = requires(T x, T2 y)
{
    {
        (x & y)
        } -> std::convertible_to<T>;
    {
        (x | y)
        } -> std::convertible_to<T>;
    {
        (x << y)
        } -> std::convertible_to<T>;
    {
        (x >> y)
        } -> std::convertible_to<T>;
    {
        (~x)
        } -> std::convertible_to<T>;
    {
        (~y)
        } -> std::convertible_to<T>;
    {
        (x ^ y)
        } -> std::convertible_to<T>;
};

template <typename T, typename T2 = T>
concept impl_arith_op =
    impl_basic_op<T, T2> && impl_bitwise_op<T, T2> && impl_modulo<T, T2>;