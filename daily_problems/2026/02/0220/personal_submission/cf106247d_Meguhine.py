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


if __name__ == "__main__":
    n = int(input())
    m = int(input())
    lim = math.isqrt(n)
    ans, ansp = n * (n + 1), n + 1

    def check(g: int):
        global ans, ansp
        p = g * (n // g + 1)
        if p <= n + m:
            nans = n * p // g
            if nans < ans:
                ans, ansp = nans, p

    for x in range(1, lim + 1):
        if n % x:
            continue
        check(x)
        check(n // x)
    print(ansp)
