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


def solve(_case: int) -> None:
    n = int(input())
    f = [tuple(map(int, input().split())) for _ in range(n)]

    e = [array('i', []) for _ in range(n)]
    deg = array('i', [0] * n)
    for i in range(n):
        ai, bi, ci = f[i]
        for j in range(i):
            aj, bj, cj = f[j]
            da, db, dc = ai - aj, bi - bj, ci - cj
            if (db**2 < 4 * da * dc) or \
                    (da == 0 and db == 0 and dc != 0):
                u, v = (i, j) if ci < cj else (j, i)
                e[u].append(v)
                deg[v] += 1

    p = deque(u for u in range(n) if not deg[u])
    seq = array('i', p.copy())
    pre = array('i', [1] * n)
    while p:
        u = p.popleft()
        for v in e[u]:
            pre[v] = fmax(pre[v], pre[u] + 1)
            deg[v] -= 1
            if not deg[v]:
                p.append(v)
                seq.append(v)

    suf = array('i', [0] * n)
    for u in reversed(seq):
        for v in e[u]:
            suf[u] = fmax(suf[u], suf[v] + 1)

    ans = [""] * n
    for i in range(n):
        ans[i] = str(pre[i] + suf[i])
    outs[_case] = " ".join(ans)


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print("\n".join(outs))
