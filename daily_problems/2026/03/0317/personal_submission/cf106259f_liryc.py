'''
https://codeforces.com/gym/106259/submission/366981580
'''
def solve(n: int, a: list[int]) -> int:
    MOD = 998244353
    a.sort()
    ans = 0
    for i in range(1, n):
        ans = (ans + i * (n - i) * (a[i] - a[i - 1])) % MOD
    return (ans << 1) * pow(n, -1, MOD) % MOD
