# -*- coding: UTF-8 -*-
import io
import os
import sys
from io import BytesIO, IOBase
import random
import bisect
import math
from fractions import Fraction
from array import array
from collections import Counter, defaultdict, deque
from copy import copy, deepcopy
from functools import cmp_to_key, lru_cache, reduce
from heapq import merge, heapify, heappop, heappush, heappushpop
from heapq import nlargest, nsmallest, heapreplace
from itertools import accumulate, combinations, permutations
from itertools import count, product, pairwise, chain
from operator import add, iand, ior, itemgetter, mul, xor
from string import ascii_lowercase, ascii_uppercase, ascii_letters
from dataclasses import dataclass
from typing import *


global de, outs
de = "--LOCAL_LEETCODE" in sys.argv
input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if y < x else y


"""
  solid - void = solid - (pi * Rmx**2 - solid)
= solid * 2 - pi * Rmx**2
"""

if __name__ == "__main__":
    n = int(input())
    a = [tuple(map(int, input().split())) for _ in range(n)]

    idx = sorted(range(n), key=lambda x: a[x][1])

    dp = [0] * n   # solid_max
    pre = [0] * n  # pre_solid_max
    global ans

    if 1:
        rr = tuple(x**2 for x in a[idx[0]])
        dp[0] = pre[0] = rr[1] - rr[0]
        ans = dp[0] - rr[0]

    for i in range(1, n):
        r_inner, r_outer = a[idx[i]]
        r_outer_2 = r_outer**2
        l, r, opt = 0, i - 1, -1
        while l <= r:
            mid = (l + r) >> 1
            if a[idx[mid]][1] <= r_inner:
                opt = mid
                l = mid + 1
            else:
                r = mid - 1
        dp[i] = r_outer_2 - r_inner**2
        if opt != -1:
            dp[i] += pre[opt]
        ans = fmax(ans, dp[i] * 2 - r_outer_2)
        pre[i] = fmax(pre[i - 1], dp[i])

    print(ans)
