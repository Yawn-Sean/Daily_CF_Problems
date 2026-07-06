import sys
input = lambda: sys.stdin.readline().rstrip()
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from collections import Counter, deque, defaultdict
from math import inf, ceil, gcd, sqrt, factorial, log2, log, isqrt
from itertools import combinations, permutations


def solve():
    n = int(input()) + 1
    v = isqrt(n)
    if v * v == n:
        print(v - 1)
        print(*range(1, v))
    else:
        print(-1)


T = int(input())
for _ in range(T):
    solve()
