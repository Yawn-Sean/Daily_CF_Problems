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
    g0 = LMII()[0]
    groups = [LMII() for _ in range(n - 1)]
    groups.sort(reverse=True)
    i = 0
    heap = list()
    while i < n - 1 and groups[i][0] > g0:
        heappush(heap, groups[i][1] - groups[i][0] + 1)
        i += 1
    ans = len(heap) + 1
    while heap and g0 >= heap[0]:
        g0 -= heappop(heap)
        while i < n - 1 and groups[i][0] > g0:
            heappush(heap, groups[i][1] - groups[i][0] + 1)
            i += 1
        ans = min(ans, len(heap) + 1)
    output(ans)


TC = 1


def main():
    for _ in range(TC):
        solve()


main()
