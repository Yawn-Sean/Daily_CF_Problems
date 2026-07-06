import sys
input = lambda: sys.stdin.readline().rstrip()
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from collections import Counter, deque, defaultdict
from math import inf, ceil, gcd, sqrt, factorial, log2, log, isqrt
from itertools import combinations, permutations

M = 100005
mod = 10**9 + 7
rev2 = (mod + 1) // 2

cnt = [0] * M
for i in range(1, M):
    for j in range(i * 2, M, i):
        cnt[j] += 1

for i in range(1, M):
    cnt[i] += cnt[i - 1]

f = [1] * M
for i in range(1, M):
    f[i] = i * f[i - 1] % mod


def solve():
    n = int(input())
    print(cnt[n] * rev2 % mod * f[n] % mod)


T = int(input())
for _ in range(T):
    solve()
