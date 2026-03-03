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


@dataclass(slots=True)
class Graph:
    n: int
    pre: array
    val: List[Any]
    head: array

    def __init__(self, n: int) -> None:
        self.n = n
        self.pre = array('i')
        self.val = []
        self.head = array('i', [-1] * (n + 1))

    def append(self, i: int, j: Any) -> None:
        self.pre.append(self.head[i])
        self.head[i] = len(self.val)
        self.val.append(j)

    def neighbors(self, i: int) -> List[Any]:
        res = []
        tmp = self.head[i]
        while tmp != -1:
            res.append(self.val[tmp])
            tmp = self.pre[tmp]
        return res

    def iterate(self, i: int) -> Any:
        tmp = self.head[i]
        while tmp != -1:
            yield self.val[tmp]
            tmp = self.pre[tmp]

    def pop(self, i: int) -> Optional[Tuple]:
        tmp = self.head[i]
        if tmp == -1:
            return None
        ret = self.val[tmp]
        self.head[i] = self.pre[tmp]
        return (ret, tmp)


if __name__ == "__main__":
    m = int(input())
    n = m << 1
    a = list(map(int, input().split()))

    p = [0] * n
    belong = [0] * n
    mnmx = [(0, 0)] * m
    gps = Graph(5 * 10**5 + 5)

    for i in range(m):
        u, v = map(int, input().split())
        p[u], p[v] = v, u
        belong[u] = belong[v] = i
        mn, mx = (a[u], a[v]) if a[u] < a[v] else (a[v], a[u])
        mnmx[i] = (mn, mx)
        gps.append(mn, i)
        if mx - mn > 2:
            gps.append(mx, i)
        else:
            lim = fmax(mn + 3, mx)
            for x in range(mn + 1, lim + 1):
                gps.append(x, i)

    outs = [""] * n
    fuck = [2] * m
    ans = m * 2
    idx = sorted(range(n), key=lambda x: a[x])

    x = -1
    for i in idx:
        curx = a[i] + 3
        while x < curx:
            x += 1
            for j in gps.iterate(x):
                ans -= fuck[j]
                res = 0
                mn, mx = mnmx[j]
                # print(f"{j=} {mn=} {mx=}")  #
                if mn > x:
                    res = 2
                elif (mn >= x - 2 and mx == x) or mx > x:
                    res = 1
                fuck[j] = res
                ans += res

        # print(f"{x=} {ans=} {fuck=}")  #
        b = belong[i]
        res = ans - fuck[b]
        if a[i] == mnmx[b][0] and a[i] + 3 < mnmx[b][1]:
            res += 1

        outs[i] = str(res + 1)

    print(" ".join(outs))
