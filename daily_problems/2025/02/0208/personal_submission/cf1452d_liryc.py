'''
https://codeforces.com/problemset/submission/1452/304997153
'''
def solve(n: int) -> int:
    Mod = 998244353

    d1, d2 = 0, 1
    for _ in range(n):
        d1, d2 = d2, (d1 + d2) % Mod

    return d1 * pow(2, -n, Mod) % Mod
