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


def calc(x: int) -> int:
    r, c = 0, 1
    while x:
        r += (x % 10) * c
        c = c * 10 + 1
        x //= 10
    return r


def solve(_case: int) -> None:
    n = int(input())
    l, r, opt = 1, n, 0
    while l <= r:
        mid = (l + r) >> 1
        if calc(mid) <= n:
            opt = mid
            l = mid + 1
        else:
            r = mid - 1
    outs[_case] = str(n - opt)


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print("\n".join(outs))
