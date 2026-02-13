# -*- coding: UTF-8 -*-
import io
import os
import sys
from io import BytesIO, IOBase
import random
import bisect
import math
from fractions import Fraction
from collections import Counter, defaultdict, deque
from copy import deepcopy
from functools import cmp_to_key, lru_cache, reduce
from heapq import merge, heapify, heappop, heappush, heappushpop
from heapq import nlargest, nsmallest, heapreplace
from itertools import accumulate, combinations, permutations
from itertools import count, product, pairwise, chain
from operator import add, iand, ior, itemgetter, mul, xor
from string import ascii_lowercase, ascii_uppercase, ascii_letters
from dataclasses import dataclass
from typing import *


global de
de = "--LOCAL_LEETCODE" in sys.argv
input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if y < x else y

"""
dp[2][最长连续上升后缀, (1~3) -> 0~2][cnt, 0~m][last, (1~n) -> 0~(n-1)]
发现转移都是转移到一段连续区间, 故用差分维护
"""

mod = 10**9 + 7


if __name__ == "__main__":
    n, m = map(int, input().split())

    def f(x: int, y: int) -> int:
        return x * (n + 1) + y

    dp = [
        [
            [0] * (n + 1) * (m + 2) for _ in range(3)
        ] for _ in range(2)
    ]
    dp[0][0][f(0, 0)] = 1
    dp[0][0][f(0, 1)] = mod - 1
    for i in range(1, n):
        nw = dp[i & 1] = [
            [0] * (n + 1) * (m + 2) for _ in range(3)
        ]
        pre = dp[(i & 1) ^ 1]
        for l in range(3):
            nl = fmin(l + 1, 2)
            for cnt in range(m + 1):
                ncnt = cnt + int(l == 2)
                cur = 0
                for last in range(i):
                    cur += pre[l][f(cnt, last)]
                    cur %= mod
                    # print(f"dp[{i - 1}][{l}][{cnt}][{last}]={cur}")
                    if cur == 0:
                        continue
                    nw[0][f(cnt, 0)] += cur
                    nw[0][f(cnt, last + 1)] -= cur
                    nw[nl][f(ncnt, last + 1)] += cur
                    nw[nl][f(ncnt, i + 1)] -= cur
    ans = 0
    nw = dp[(n & 1) ^ 1]
    for l in range(3):
        cur = 0
        for last in range(0, n):
            cur += nw[l][f(m, last)]
            cur %= mod
            ans += cur
    print(ans % mod)
