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
    n = II()
    s = LI()
    if n & 1:
        output(":(")
        return
    l, r = n // 2 - s.count("("), n // 2 - s.count(")")
    if l < 0 or r < 0:
        output(":(")
        return 
    for i, ch in enumerate(s):
        if ch == "?":
            if l:
                s[i] = "("
                l -= 1
            else:
                s[i] = ")"
    c = 0
    for ch in s[:-1]:
        if ch == "(":
            c += 1
        else:
            c -= 1
        if c <= 0:
            output(":(")
            return
    output("".join(s))


TC = 1

def main():
    for _ in range(TC):
        solve()

main()

