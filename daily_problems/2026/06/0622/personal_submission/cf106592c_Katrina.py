import sys
input = lambda: sys.stdin.readline().rstrip()
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from collections import Counter, deque, defaultdict
from math import inf, ceil, gcd, sqrt, factorial, log2, log
from itertools import combinations, permutations


def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    lo, hi = 0, max(a)
    while lo < hi:
        mid = (lo + hi + 1) // 2
        s = 0
        for x in a:
            s += x if x < mid else mid
        if s <= n:
            lo = mid
        else:
            hi = mid - 1
    
    T = lo
    b = []
    s = 0
    for x in a:
        val = x if x < T else T
        b.append(val)
        s += val
    
    r = n - s
    for i in range(k):
        if r == 0:
            break
        if a[i] > T:
            b[i] += 1
            r -= 1
    
    print(*b)


T = int(input())
for _ in range(T):
    solve()
