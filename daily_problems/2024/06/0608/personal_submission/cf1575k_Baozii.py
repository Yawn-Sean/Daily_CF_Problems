import os
import random
import sys
from collections import defaultdict, Counter, deque
from functools import cache, reduce
from itertools import pairwise, combinations, permutations, groupby, accumulate
from bisect import bisect_left, bisect_right, insort_left, insort_right

input = sys.stdin.readline
output = lambda x: sys.stdout.write(str(x) + "\n")


I = lambda: input().rstrip("\n")
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(MII())
TMII = lambda: tuple(MII())
LI = lambda: list(I())


MOD = 10 ** 9 + 7

def solve():
    n, m, k, r, c = MII()
    ax, ay, bx, by = MII()
    if (ax, ay) == (bx, by):
        output(pow(k, n * m, MOD))
    else:
        output(pow(k, n * m - r * c, MOD))

TC = 1

def main():
    for _ in range(TC):
        solve()

main()
