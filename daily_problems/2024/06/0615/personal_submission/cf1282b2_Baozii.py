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
outputL = lambda x: sys.stdout.write(" ".join(map(str, x)) + "\n")


I = lambda: input().rstrip("\n")
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(MII())
TMII = lambda: tuple(MII())
LI = lambda: list(I())

def solve():
    n, p, k = MII()
    arr = LMII()
    arr.sort()
    if p < arr[0]:
        output(0)
        return
    pre = list(accumulate(arr, initial=0))
    ans = 0
    for i in range(k + 1):
        if pre[i] > p:
            break
        cnt = i
        s = pre[i]
        for j in range(i + k - 1, n, k):
            if s + arr[j] <= p:
                cnt += k
                s += arr[j]
            else:
                break
        ans = max(ans, cnt)
    output(ans)


TC = II()

def main():
    for _ in range(TC):
        solve()

main()
