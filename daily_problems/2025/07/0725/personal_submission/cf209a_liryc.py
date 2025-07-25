'''
https://codeforces.com/problemset/submission/209/330749412
'''
# classical DP
def solve(n: int) -> int:
    MOD = 1000000007
    d0, d1 = 0, 0
    for _ in range(n):
        d1 = (d1 + d0 + 1) % MOD
        d0, d1 = d1, d0
    return (d0 + d1) % MOD
