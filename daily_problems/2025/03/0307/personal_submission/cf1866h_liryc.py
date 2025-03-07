'''
https://codeforces.com/problemset/submission/1866/309304441
'''
def solve(n: int, k: int) -> int:
    MOD = 998244353
    ans, pt = 0, 1
    for c in range(min(n, k) + 1):
        ans += pt * (pow(c + 1, k - c + 1, MOD) - pow(c, k - c + 1, MOD)) % MOD
        pt = pt * (n - c) % MOD * (c + 1) % MOD
    return ans % MOD
