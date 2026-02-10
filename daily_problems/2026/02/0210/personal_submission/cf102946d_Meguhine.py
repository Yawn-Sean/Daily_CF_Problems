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
from itertools import count, product, pairwise
from operator import add, iand, ior, itemgetter, mul, xor
from string import ascii_lowercase, ascii_uppercase, ascii_letters
from dataclasses import dataclass
from typing import *


global de
de = "--LOCAL_LEETCODE" in sys.argv
input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if y < x else y

global _a
global _b
global ans


def ask(x: int, y: int) -> int:
    print(f"? {x} {y}", flush=True)
    if de:
        return fmax(_a[x], _b[y])
    else:
        return int(input())


if __name__ == "__main__":
    n = int(input())
    if de:
        _a = list(map(int, input().split()))
        _b = list(map(int, input().split()))
    aib0 = [ask(i, 0) for i in range(n)]
    if aib0[0] == aib0[1] == n:  # b[0]==n
        amx_idx = max(
            range(0, n),
            key=lambda i: ask(i, 1)
        )
        ans = n - amx_idx if amx_idx != 0 else 0
    else:
        amx_idx = max(
            range(0, n),
            key=lambda i: aib0[i]
        )
        a_not_mx_idx = 0 if amx_idx != 0 else 1
        bmx_idx = max(
            range(0, n),
            key=lambda i: ask(a_not_mx_idx, i)
        )
        ans = bmx_idx - amx_idx
        if ans < 0:
            ans += n

    print(f"! {ans}")
    if de:
        for i in range(n):
            assert _a[i] == _b[(i + ans) % n]
