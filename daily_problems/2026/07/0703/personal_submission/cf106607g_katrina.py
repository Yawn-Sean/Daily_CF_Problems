import sys
input = lambda: sys.stdin.readline().rstrip()
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from collections import Counter, deque, defaultdict
from math import inf, ceil, gcd, sqrt, factorial, log2, log
from itertools import combinations, permutations


def solve():
    n, m, k = map(int, input().split())
    ans = n
    if (n - k) % 2 != 0:
        ans -= 1
    ans = min(ans, k)
    if m % 2 == 0:
        ans = min(ans, n * m - k)
    print(ans)


T = int(input())
for _ in range(T):
    solve()
