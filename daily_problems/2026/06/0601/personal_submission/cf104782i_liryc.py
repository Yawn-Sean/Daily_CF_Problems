'''
https://codeforces.com/gym/104782/submission/376887312
'''
def solve(k: int, s: int, t: int) -> int:
    MOD = 1000000007
    fac = Factorial(s + 1, MOD)
    d, m = divmod(k, t)
    ans = 0
    if m == 0:
        if s % d == 0:
            x = s // d
            ans = fac.combi(x - 1, t - 1)
        return ans
    for x in range(s + 1):
        if (s - d * x) % (d + 1) == 0:
            y = (s - d * x) // (d + 1)
            ans += fac.combi(x - 1, t - m - 1) * fac.combi(y - 1, m - 1)
            ans %= MOD
    return ans
