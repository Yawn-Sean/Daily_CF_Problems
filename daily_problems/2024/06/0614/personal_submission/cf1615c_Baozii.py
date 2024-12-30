import os
import random
import sys
from typing import *
from collections import defaultdict, Counter, deque
from functools import cache, reduce
from itertools import pairwise, combinations, permutations, groupby, accumulate
from bisect import bisect_left, bisect_right, insort_left, insort_right
from heapq import *

input = sys.stdin.readline
output = lambda x: sys.stdout.write(str(x) + "\n")
outputL = lambda x: sys.stdout.write(" ".join(map(str, data)) + "\n")


I = lambda: input().rstrip("\n")
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(MII())
TMII = lambda: tuple(MII())
LI = lambda: list(I())

def solve():
    n = II()
    a = I()
    b = I()
    c1 = a.count("1")
    c2 = b.count("1")
    ans = float("inf")
    if c1 == c2:
        ans = sum(int(ch1 != ch2) for ch1, ch2 in zip(a, b))
    if n - c1 + 1 == c2:
        ans = min(ans, sum(int(ch1 == ch2) for ch1, ch2 in zip(a, b)) + 2 - int("1" in b) * 2)
    if ans == float("inf"):
        output(-1)
    else:
        output(ans)


TC = II()

def main():
    for _ in range(TC):
        solve()

main()
