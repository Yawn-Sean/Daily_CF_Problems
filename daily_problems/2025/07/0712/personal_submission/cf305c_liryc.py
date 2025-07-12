'''
https://codeforces.com/problemset/submission/305/328601569
'''
# math, greedy
from itertools import groupby
def solve(n: int, a: list[int]) -> int:
    b, x, ans = -1, 0, 0
    for k, g in groupby(a):
        c = sum(1 for _ in g)
        if b < 0:
            ans, b, x = k, k, c
        elif k >= b + x.bit_length():
            ans += k - b - x.bit_count()
            b, x = k, c
        else:
            x += (1 << k - b) * c
    ans += x.bit_length() - x.bit_count()
    return ans
