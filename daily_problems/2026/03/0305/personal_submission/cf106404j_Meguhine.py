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


global outs
de = "--LOCAL_LEETCODE" in sys.argv
input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if y < x else y


# if 1:
#     lim = 10**6
#     a = [1, 1]
#     while a[-1] <= lim:
#         a.append(a[-1] + a[-2])
#     print(len(a), a)

# if #non-zero >= 31, then YES
# otherwise, brute force


if __name__ == "__main__":
    n, m = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]

    cnt = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            cnt[i][j] = (not not a[i - 1][j - 1]) + cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1]

    # 1-based-index
    def f(sx: int, sy: int, tx: int, ty: int) -> int:
        return cnt[tx][ty] - cnt[sx - 1][ty] - cnt[tx][sy - 1] + cnt[sx - 1][sy - 1]

    R = [[1 << 11] * (m) for _ in range(n)]
    for i in range(n):
        if a[i][m - 1]:
            R[i][m - 1] = m - 1
        for j in range(m - 2, -1, -1):
            if a[i][j]:
                R[i][j] = j
            else:
                R[i][j] = R[i][j + 1]

    Q = int(input())
    outs = [""] * Q

    for _ in range(Q):
        sx, sy, tx, ty = map(int, input().split())

        cc = f(sx, sy, tx, ty)
        if cc >= 31:
            outs[_] = "YES"
            continue
        if cc <= 2:
            outs[_] = "NO"
            continue

        i = sx
        opt = [0] * cc
        tot = 0

        while True:
            i += bisect.bisect_left(range(i, tx + 1), 1, key=lambda j: f(i, sy, j, ty))
            if i > tx:
                break

            j = sy - 1
            while True:
                j = R[i - 1][j]
                if j >= ty:
                    break

                opt[tot] = a[i - 1][j]
                tot += 1

                j += 1
                if j >= ty:
                    break

            i += 1
            if i > tx:
                break

        opt.sort()
        for i in range(2, cc):
            if opt[i - 1] + opt[i - 2] > opt[i]:
                outs[_] = "YES"
                break
        else:
            outs[_] = "NO"

    print("\n".join(outs))
