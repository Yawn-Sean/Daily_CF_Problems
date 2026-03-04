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


@dataclass(slots=True)
class DSU:
    n: int
    fa: array
    sz: array

    def __init__(self, n: int) -> None:
        self.n = n
        self.fa = array('i', range(n))
        self.sz = array('i', [1] * n)

    def get(self, x: int) -> int:
        while x != self.fa[x]:  # DONT MERGE !!!
            self.fa[x] = self.fa[self.fa[x]]
            x = self.fa[x]
        return x

    def same(self, x: int, y: int) -> bool:
        return self.get(x) == self.get(y)

    def merge(self, x: int, y: int) -> bool:
        x, y = self.get(x), self.get(y)
        if x == y:
            return False
        if self.sz[x] < self.sz[y]:
            x, y = y, x
        self.sz[x] += self.sz[y]
        self.fa[y] = x
        return True

    def size(self, x: int) -> int:
        return self.sz[self.get(x)]


MOD = 10**9 + 7


if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))

    e = Graph(n)
    for _ in range(1, n):
        u, v = map(lambda x: int(x) - 1, input().split())
        e.append(u, v)
        e.append(v, u)

    idx = sorted(range(n), key=lambda x: a[x])

    def work() -> int:
        res = 0
        dsu = DSU(n)
        vis = array('b', [False] * n)
        for u in idx:
            vis[u] = True
            for v in e.iterate(u):
                if vis[v]:
                    res += dsu.size(v) * dsu.size(u) * a[u] % MOD
                    dsu.merge(u, v)
        return res % MOD

    ans = work()

    idx = idx[::-1]
    ans -= work()

    ans = ans * pow(n * (n - 1) // 2 % MOD, MOD - 2, MOD) % MOD
    print(ans)
