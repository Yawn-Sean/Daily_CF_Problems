'''
https://codeforces.com/gym/104287/submission/356462347
'''
def solve(n: int) -> int:
    MOD = 1000000007
    d1, d2, d3 = 0, 0, 1
    for _ in range(2, n + 1):
        d1, d2, d3 = d1 * 2 + (d2 + d3) * (d3 + 1) * 4, (d2 + d3) * 2, d3 * 2 + 1
        d1, d2, d3 = d1 % MOD, d2 % MOD, d3 % MOD
    return d1
