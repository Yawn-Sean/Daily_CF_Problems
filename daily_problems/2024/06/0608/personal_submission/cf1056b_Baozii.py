import os
import random
import sys
from collections import defaultdict, Counter, deque
from functools import cache, reduce
from itertools import pairwise, combinations, permutations, groupby, accumulate
from bisect import bisect_left, bisect_right, insort_left, insort_right
from math import gcd, lcm, isqrt

input = sys.stdin.readline
output = lambda x: sys.stdout.write(str(x) + "\n")


I = lambda: input().rstrip("\n")
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(MII())
TMII = lambda: tuple(MII())
LI = lambda: list(I())

def solve():
    n, m = MII()
    mods = [0] * m
    for i in range(1, m + 1):
        mods[i - 1] = i * i % m
    cnt = Counter()
    q, r = divmod(n, m)
    for i, mod in enumerate(mods):
        cnt[mod] += q + (1 if i < r else 0)
    ans = cnt[0] * cnt[0] + sum(cnt[i] * cnt[m - i] for i in range(1, m))
    output(ans)


TC = 1

def main():
    for _ in range(TC):
        solve()

main()

