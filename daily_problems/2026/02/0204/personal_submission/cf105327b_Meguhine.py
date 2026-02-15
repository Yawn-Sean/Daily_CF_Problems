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
global outs
de = "--LOCAL_LEETCODE" in sys.argv
input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if y < x else y


@dataclass(slots=True)
class DSU:
    n: int
    fa: List[int]
    sz: List[int]

    def __init__(self, n: int) -> None:
        self.n = n
        self.fa = list(range(n))
        self.sz = [1] * n

    def get(self, x: int) -> int:
        while x != self.fa[x]:
            x = self.fa[x] = self.fa[self.fa[x]]
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


if __name__ == "__main__":
    n, m = map(int, input().split())  # #movie, #actor

    a = [[] for _ in range(m + 1)]  # actor i's movies are a[i]
    for i in range(1, n + 1):
        o = list(map(int, input().split()))
        for j in range(1, len(o)):
            a[o[j]].append(i)

    e = [[] for _ in range(n + 1)]
    mp = [-1] * (m + 1)
    dsu = DSU(n + 1)
    for i in range(1, m + 1):
        if not a[i]:
            continue
        mp[i] = a[i][0]
        for j in range(1, len(a[i])):
            x, y = a[i][0], a[i][j]
            if dsu.merge(x, y):
                e[x].append((y, i))
                e[y].append((x, i))

    Q = int(input())
    outs = [""] * Q
    path = []

    def dfs(u: int, pre: int, dest: int) -> int:
        if u == dest:
            path.append(str(u))
            return 2
        for v, i in e[u]:
            if v == pre:
                continue
            tmp = dfs(v, u, dest)
            if tmp != -1:
                path.append(str(i))
                path.append(str(u))
                return tmp + 1
        return -1

    for _ in range(Q):
        x, y = map(int, input().split())
        ed, st = mp[x], mp[y]
        if st == -1 or ed == -1:
            outs[_] = "-1"
            continue
        path = [str(x)]
        cnt = dfs(st, -1, ed)
        if cnt == -1:
            outs[_] = "-1"
        else:
            path.append(str(y))
            outs[_] = f"{cnt}\n{' '.join(path)}"
    print("\n".join(outs))
