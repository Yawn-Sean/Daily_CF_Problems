n, m, k = MII()

a, b = divmod(n, k)

if n - a >= m:
    print(m)
else:
    left = m - a * (k - 1) - b
    ans = m - left * k + k * 2 * (pow(2, left, MOD) - 1)
    print(ans % MOD)
