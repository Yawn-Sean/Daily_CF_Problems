import sys
input = lambda: sys.stdin.readline().rstrip()
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from collections import Counter, deque, defaultdict
from math import inf, ceil, gcd, sqrt, factorial, log2, log, isqrt
from itertools import combinations, permutations

mod = 10**9 + 7


def solve():
    n, m = map(int, input().split())
    tmp1 = [0] * (m + 1)
    tmp2 = [0] * (m + 1)
    for _ in range(n):
        l, r = map(int, input().split())
        tmp1[l] = (tmp1[l] + m + 1 - r) % mod
        tmp2[r] = (tmp2[r] + l) % mod
    
    ans = 0
    total = 0
    for i in range(m, 0, -1):
        ans = (ans + total * tmp2[i]) % mod
        total = (total + tmp1[i]) % mod
    
    print(ans)


T = int(input())
for _ in range(T):
    solve()
