def CF935D():
    n, m = MII()
    s1 = LII()
    s2 = LII()
    cur = 1
    ans = 0
    mod = pow(m, MOD1 - 2, MOD1)
    mod2 = pow(2, MOD1 - 2, MOD1)
    for x, y in zip(s1, s2):
        if x == y:
            if x == 0:
                cur *= mod
                cur %= MOD1
                ans += (m - 1) * m * mod2 % MOD1 * cur % MOD1 * mod % MOD1
                ans %= MOD1
        elif x > y:
            if y == 0:
                cur *= mod
                cur %= MOD1
                ans += cur * (x - 1)
                ans %= MOD1
            else:
                ans += cur
                ans %= MOD1
                break
        else:
            if x == 0:
                cur *= mod
                cur %= MOD1
                ans += cur * (m - y)
                ans %= MOD1
            else:
                break
    print(ans)
    