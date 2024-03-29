# -*- coding: utf-8 -*-
import sys
from collections import Counter

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

n = I()
hst = Counter()
ans = 0


def idx(c_):
    return ord(c_) - ord('a')


for _ in range(n):
    s = input()
    x = 0
    for c in s:
        x ^= 1 << idx(c)

    ans += hst[x]
    for i in range(26):
        if x & (1 << i):
            y = x & (~(1 << i))
            ans += hst[y]

    for i in range(26):
        if x & (1 << i) == 0:
            y = x | (1 << i)
            ans += hst[y]
    hst[x] += 1
print(ans)
