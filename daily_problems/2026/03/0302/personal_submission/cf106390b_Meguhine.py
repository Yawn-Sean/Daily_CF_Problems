# -*- coding: UTF-8 -*-
from types import GeneratorType
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


def bootstrap(f, stk=[]):
    def wrappedfunc(*args, **kwargs):
        if stk:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stk.append(to)
                    to = next(to)
                else:
                    stk.pop()
                    if not stk:
                        break
                    to = stk[-1].send(to)
            return to
    return wrappedfunc


LEN_MASK = 20
MASK = (1 << LEN_MASK) - 1


def solve(_case: int) -> None:
    n = int(input())

    e = Graph(n)
    for _ in range(1, n):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        e.append(u, w << LEN_MASK | v)
        e.append(v, w << LEN_MASK | u)

    gps = Graph(n)
    fa = [-1] * n
    faw = [0] * n
    pre = [0] * n

    @bootstrap
    def dfs(u: int, d: int):
        gps.append(d, u)
        d += 1
        _fa = fa[u]
        for wv in e.iterate(u):
            v = wv & MASK
            w = wv >> LEN_MASK
            if v == _fa:
                continue
            fa[v] = u
            faw[v] = w
            pre[v] = pre[u] + w
            yield dfs(v, d)
        yield

    dfs(0, 0)

    dp = pre.copy()
    for d in range(1, n):
        cur = 10**18
        for u in gps.iterate(d):
            cur = fmin(cur, pre[u])
        for u in gps.iterate(d):
            dp[u] = min(dp[u], cur, dp[fa[u]] + faw[u])

    outs[_case] = ' '.join(map(str, dp))


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print("\n".join(outs))
