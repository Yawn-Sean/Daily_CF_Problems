import sys
input = lambda: sys.stdin.readline().rstrip()
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from collections import Counter, deque, defaultdict
from math import inf, ceil, gcd, sqrt, factorial, log2, log
from itertools import combinations, permutations


def solve():
    n, m = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(n)]
    
    cnt = [[0] * m for _ in range(n)]
    
    for i in range(n):
        d = {}
        for j in range(m - 1, -1, -1):
            key = grid[i][j] + j
            cnt[i][j] = d.get(key, 0)
            d[key] = d.get(key, 0) + 1
    
    ans = 0
    for j in range(m):
        d = {}
        for i in range(n - 1, -1, -1):
            key = grid[i][j] + i
            ans += cnt[i][j] * d.get(key, 0)
            d[key] = d.get(key, 0) + 1
    
    print(ans)


T = 1
for _ in range(T):
    solve()
