"""
question url  : https://codeforces.com/problemset/problem/869/C
submission url: https://codeforces.com/contest/869/submission/262956484
"""

def solve():
    MOD  = 998244353
    a, b, c = map(int, input().split())
    f = [1] * 5010
    g = [1] * 5010
    for i in range(1, 5010):
        f[i] = f[i - 1] * i % MOD 
    g[-1] = pow(f[-1], MOD - 2, MOD)
    for i in range(5008, -1, -1):
        g[i] = g[i + 1] * (i + 1) % MOD 

    def func(x, y):
        res = 0 
        for i in range(min(x, y) + 1):
            res += f[x] * g[i] % MOD * g[x - i] % MOD * f[y] * g[i] % MOD * g[y - i] % MOD * f[i] % MOD
            res %= MOD 
        return res 
    print((func(a, b) * func(b, c) * func(a, c)) % MOD)
solve()
