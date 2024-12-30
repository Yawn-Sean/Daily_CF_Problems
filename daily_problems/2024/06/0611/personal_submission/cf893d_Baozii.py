import os
import random
import sys
from collections import defaultdict, Counter, deque
from functools import cache, reduce
from itertools import pairwise, combinations, permutations, groupby, accumulate
from bisect import bisect_left, bisect_right, insort_left, insort_right
from heapq import *

input = sys.stdin.readline
output = lambda x: sys.stdout.write(str(x) + "\n")


I = lambda: input().rstrip("\n")
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(MII())
TMII = lambda: tuple(MII())
LI = lambda: list(I())

def solve():
    n, d = MII()
    arr = LMII()
    ans, l, r = 0, 0, 0
    for num in arr:
        if num:
            l += num
            r = min(r + num, d)
            if l > d:
                output(-1)
                return
        else:
            if r < 0:
                l, r = 0, d
                ans += 1
            else:
                l = max(l, 0)
    output(ans)


TC = 1

def main():
    for _ in range(TC):
        solve()

main()
