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


B = 17
MASK = (1 << B) - 1


def solve(_case: int) -> None:
    n, m = map(int, input().split())
    f = list(map(int, input().split()))

    e = Graph(n)
    for _ in range(m):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        e.append(u, w << B | v)
        e.append(v, w << B | u)

    p = [f[x] << B | x for x in range(n)]
    heapify(p)
    while p:
        du = heappop(p)
        d = du >> B
        u = du & MASK
        if f[u] != d:
            continue
        for wv in e.iterate(u):
            w = wv >> B
            v = wv & MASK
            if f[v] > d + w:
                f[v] = d + w
                heappush(p, f[v] << B | v)

    dp = [10**16] * n
    dp[0] = 0
    p = [0]

    while p:
        du = heappop(p)
        d = du >> B
        u = du & MASK
        if dp[u] != d:
            continue
        for wv in e.iterate(u):
            w = wv >> B
            v = wv & MASK
            nd = d + w
            if nd <= f[v] and nd < dp[v]:
                dp[v] = nd
                heappush(p, nd << B | v)

    outs[_case] = "YES" if dp[-1] <= f[-1] else "NO"


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print("\n".join(outs))
