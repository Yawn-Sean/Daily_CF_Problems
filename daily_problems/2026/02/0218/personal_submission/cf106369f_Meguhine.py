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


if __name__ == "__main__":
    b1, b2, h = map(int, input().split())
    s = (b1 + b2) * h / 2

    def f(x: float) -> float:
        s1 = b1 * x / 2
        s2 = b2 * (h - x) / 2
        s3 = (s - s1 - s2) / 2
        return max(s1, s2, s3) - min(s1, s2, s3)

    l, r, ans = 0, h, 10**9
    for _ in range(90):
        lmid = (l * 2 + r) / 3
        rmid = (l + r * 2) / 3
        fl = f(lmid)
        fr = f(rmid)
        ans = min(ans, fl, fr)
        if fl > fr:
            l = lmid
        else:
            r = rmid
    print(f"{ans:.8f}")
