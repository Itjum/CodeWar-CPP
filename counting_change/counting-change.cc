constexpr long long count_change_rec(long long amount, long long coins[], int i)
{
    if (amount == 0)
    {
        return 1;
    }
    else if (amount < 0 || i == 8)
    {
        return 0;
    }
    else
    {
        long long fstcoin = count_change_rec(amount - coins[i], coins, i);
        long long withoutfcoin = count_change_rec(amount, coins, i + 1);
        return fstcoin + withoutfcoin;
    }
}

constexpr long long count_change(const long long amount)
{
    long long coins[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
    return count_change_rec(amount, coins, 0);
}
