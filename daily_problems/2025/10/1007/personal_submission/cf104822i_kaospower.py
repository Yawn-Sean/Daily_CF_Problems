from typing import List
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapreplace
from itertools import pairwise, permutations, accumulate
from math import inf, comb, sqrt, ceil, floor, log, log2, log10
from functools import cache
from math import gcd
from collections import defaultdict, Counter
import io, os
import sys

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y


def solve():
    a = int(input())
    va = a
    vals = {}
    for p in prs:
        if p * p > va: break
        if va % p == 0:
            vals[p] = 0
            while va % p == 0:
                vals[p] += 1
                va //= p

    if va > 1:
        vals[va] = 1

    factors = [1]
    for x in vals:
        c = vals[x]
        k = len(factors)
        for i in range(c * k):
            factors.append(factors[i] * x)

    factors.sort()
    ans = a * a - a

    for i in range(len(factors) - 1):
        val = factors[i] * factors[len(factors) - 2 - i]
        ans = fmin(ans, a * a // val - a)
    print(ans)


M = 40000
is_prime = [1] * (M + 1)
prs = []

for i in range(2, M + 1):
    if is_prime[i]:
        prs.append(i)
        for j in range(i * 2, M + 1, i):
            is_prime[j] = 0

t = int(input())
for i in range(t):
    solve()
