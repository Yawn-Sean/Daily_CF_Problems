import sys
input = lambda: sys.stdin.readline().rstrip()
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from collections import Counter, deque, defaultdict
from math import inf, ceil, gcd, sqrt, factorial, log2, log
from itertools import combinations, permutations


def solve():
    n = int(input())
    ans = n * (n - 1) // 2
    c0 = c1 = 0
    for _ in range(n):
        x, y = map(int, input().split())
        if x > y:
            ans -= c0
            c0 += 1
        elif x < y:
            ans -= c1
            c1 += 1
    print(ans)


T = int(input())
for _ in range(T):
    solve()
