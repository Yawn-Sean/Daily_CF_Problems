# -*- coding: utf-8 -*-
import random
import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
TI = lambda: tuple(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

rnd = random.getrandbits(20)

tcn = 3
for _tcn_ in range(tcn):
    n, k = MI()
    A = LI()
    hst = [Counter() for _ in range(11)]

    for a in A:
        c1 = len(str(a))
        hst[c1][a % k ^ rnd] += 1

    ans = 0
    for a in A:
        cur = a
        d = len(str(cur))
        for i in range(1, 11):
            cur *= 10
            cur %= k
            ans += hst[i][(-cur) % k ^ rnd]
            if i == d and (cur + a) % k == 0:
                ans -= 1
    print(ans)
