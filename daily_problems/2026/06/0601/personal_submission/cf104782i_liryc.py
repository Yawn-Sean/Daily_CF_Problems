def solve(k: int, s: int, t: int) -> int:
    MAXN = 5000004
    MOD = 1000000007
    fac = Factorial(MAXN, MOD)
    d, m = divmod(k, t)
    ans = 0
    for x in range(s + 1):
        if (s - d * x) % (d + 1) == 0:
            y = (s - d * x) // (d + 1)
            ans += fac.combi(x - 1, t - m - 1) * fac.combi(y - 1, m - 1)
            ans %= MOD
    return ans
