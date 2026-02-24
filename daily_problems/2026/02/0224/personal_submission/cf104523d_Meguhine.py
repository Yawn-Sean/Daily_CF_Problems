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


def solve(_case: int) -> None:
    n, K = map(int, input().split())
    a = list(map(int, input().split()))

    def f(l: int, r: int) -> int:
        return l * n + r

    def calc2(x: int, y: int) -> int:
        return 1 if abs(x - y) <= K else n * 2

    def calc3(x: int, y: int, z: int) -> int:
        mx, mn = max(x, y, z), min(x, y, z)
        return 1 if mx - mn <= K else n * 3

    inf = n * n
    dp = [0] * (n + 1) * (n + 1)

    for l in range(0, n):
        dp[f(l, l)] = inf
        if l + 1 < n:
            dp[f(l, l + 1)] = calc2(a[l], a[l + 1])
        if l + 2 < n:
            dp[f(l, l + 2)] = min(
                calc3(a[l], a[l + 1], a[l + 2]),
                calc2(a[l], a[l + 1]) + n,
                calc2(a[l + 1], a[l + 2]) + n
            )

    for _len in range(4, n + 1):
        r = _len - 1
        for l in range(0, n):
            res = fmin(dp[f(l + 1, r)], dp[f(l, r - 1)]) + n

            if 1:
                inner = dp[f(l + 1, r - 1)]
                if inner < n:
                    res = fmin(res, inner + calc2(a[l], a[r]))

            for m in range(l + 1, r):
                res = fmin(res, dp[f(l, m)] + dp[f(m + 1, r)])
                lm_inner = dp[f(l + 1, m - 1)]
                mr_inner = dp[f(m + 1, r - 1)]
                if lm_inner < n:
                    res = fmin(res, lm_inner + dp[f(m + 1, r)] +
                               calc2(a[l], a[m]))
                if mr_inner < n:
                    res = fmin(res, mr_inner + dp[f(l, m - 1)] +
                               calc2(a[m], a[r]))
                if lm_inner < n and mr_inner < n:
                    res = fmin(res, lm_inner + mr_inner +
                               calc3(a[l], a[m], a[r]))

            dp[f(l, r)] = res
            # print(f"{l=} {r=} {divmod(res, n)}")  #

            r += 1
            if r >= n:
                break

    outs[_case] = " ".join(map(str, divmod(dp[f(0, n - 1)], n)))


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print("\n".join(outs))
