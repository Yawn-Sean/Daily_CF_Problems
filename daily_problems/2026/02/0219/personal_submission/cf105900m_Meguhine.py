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


global de
global outs
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


if __name__ == "__main__":
    n, m = map(int, input().split())
    INF, e = 10**12, Graph(n)
    for _ in range(m):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        e.append(u, (v, w))

    dis = [INF] * n
    mxw = [INF] * n
    dis[0] = mxw[0] = 0

    def f(d: int, u: int) -> int:
        return d * n + u

    heap = []
    heappush(heap, f(0, 0))
    while heap:
        d, u = divmod(heappop(heap), n)
        if d != dis[u]:
            continue
        for v, w in e.iterate(u):
            nd = d + w
            if dis[v] > nd:
                dis[v] = nd
                mxw[v] = fmax(mxw[u], w)
                heappush(heap, f(nd, v))
            elif dis[v] == nd:
                mxw[v] = fmin(mxw[v], fmax(mxw[u], w))
    print(f"{dis[n - 1]} {mxw[n - 1]}")
