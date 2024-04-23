# -*- coding : utf-8 -*-
import sys
from functools import cmp_to_key

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353


def cmp(p0, p1):
    s0, h0 = p0
    s1, h1 = p1
    if s0 * h1 > s1 * h0:
        return -1
    elif s0 * h1 < s1 * h0:
        return 1
    return 0


n = I()
ss = [input() for _ in range(n)]
nums = []
tot = 0
for s in ss:
    x = 0
    for c in s:
        if c == 's':
            x += 1
        else:
            tot += x
    nums.append([x, len(s) - x])

nums.sort(key=cmp_to_key(cmp))
x = 0
for c1, c2 in nums:
    tot += c2 * x
    x += c1
print(tot)
