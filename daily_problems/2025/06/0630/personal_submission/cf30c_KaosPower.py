from typing import List
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapreplace
from itertools import pairwise, permutations, accumulate
from math import inf, comb, sqrt, ceil, floor, log, log2, log10
from functools import cache
from functools import lru_cache
from math import gcd
from collections import defaultdict, Counter
import io, os
import sys

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def solve():
    n = int(input())
    arr=[list(map(float,input().split())) for _ in range(n)]
    arr.sort(key=lambda p:p[2])
    f=[0]*n
    for i in range(n-1,-1,-1):
        xi, yi, ti, pi = arr[i]
        for j in range(i+1,n):
            xj, yj, tj, pj = arr[j]
            if (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) <= (tj - ti) * (tj - ti):
                f[i] = fmax(f[i], f[j])
        f[i]+=pi
    print(max(f))
solve()
