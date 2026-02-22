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


class FenwickTree:

    def __init__(self, n: int = 0) -> None:
        self._n = n
        self.data = [0] * n

    def add(self, p: int, x: Any) -> None:
        assert 0 <= p < self._n

        p += 1
        while p <= self._n:
            self.data[p - 1] += x
            p += p & -p

    def sum(self, left: int, right: int) -> Any:
        assert 0 <= left <= right <= self._n

        return self._sum(right) - self._sum(left)

    def _sum(self, r: int) -> Any:
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r

        return s


MOD = 998244353


if __name__ == "__main__":
    n = int(input())
    a = [[] for _ in range(n)]
    m = 0

    if 1:
        disc_set = set()
        for i in range(n):
            m += int(input())  # size of a[i]
            a[i] = list(map(int, input().split()))
            for x in a[i]:
                disc_set.add(x)
        disc = sorted(disc_set)
        disc_dict = {x: i for i, x in enumerate(disc)}
        for v in a:
            for i in range(len(v)):
                v[i] = disc_dict[v[i]]
            v.sort()
        # print(a)  #

    opt = [0] * n
    fen = FenwickTree(m)
    for i in range(n):
        b = a[i]
        res, tot = b[0], fen._sum(b[0])
        for j in range(1, len(b)):
            if tot == fen._sum(b[j]):
                res = b[j]
            else:
                break
        fen.add(res, 1)
        opt[i] = res

    idx = sorted(range(n), key=lambda x: opt[x] * m + x, reverse=True)
    # print(f"{opt=}")  #
    # print(f"{idx=}")  #
    dp = [1] * len(a[idx[0]])
    for _i in range(1, n):
        cansame = idx[_i - 1] > idx[_i]
        p, q = a[idx[_i - 1]], a[idx[_i]]
        nw = [0] * len(q)
        s, i = 0, len(p) - 1
        for j in range(len(q) - 1, -1, -1):
            while i >= 0 and \
                    (p[i] > q[j] or (cansame and p[i] == q[j])):
                s = (s + dp[i]) % MOD
                i -= 1
            nw[j] = s
        dp = nw
        # print(p, q, cansame)  #
        # print(dp)  #
    ans = sum(dp) % MOD
    print(ans)
