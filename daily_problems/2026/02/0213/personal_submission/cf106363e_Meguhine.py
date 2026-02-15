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


if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))

    pos = [0] * n
    for i, x in enumerate(a):
        pos[x] = i

    dk = [0] * (n + 1)
    db = [0] * (n + 1)

    def add(l: int, r: int, k: int, b: int) -> None:
        dk[l] += k
        dk[r + 1] -= k
        db[l] += b
        db[r + 1] -= b

    l, r = n, 0
    for p in pos:
        l = fmin(l, p)
        r = fmax(r, p)
        if l != 0:
            # [0,l-1]
            # (i+1)*(n-r)
            add(0, l - 1, n - r, n - r)
        if r != n - 1:
            # [r+1,n-1]
            # (l+1)*(n-i)
            add(r + 1, n - 1, -(l + 1), n * (l + 1))
        # [l,r]
        # (l+1)*(n-r)
        add(l, r, 0, (l + 1) * (n - r))

    dk.pop()
    db.pop()

    ks = accumulate(dk)
    bs = accumulate(db)

    ans = [""] * n
    for i, (k, b) in enumerate(zip(ks, bs)):
        ans[i] = str(k * i + b)
    print("\n".join(ans))
