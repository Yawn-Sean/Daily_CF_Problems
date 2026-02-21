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
    n, B = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    idx = sorted(range(n), key=lambda x: -b[x])
    dp = [B + 1] * (n + 1)
    dp[0] = 0
    for c, i in enumerate(idx):
        _a, _b = a[i], b[i]
        for x in range(c, -1, -1):
            dp[x + 1] = fmin(dp[x + 1], dp[x] + _b * x + _a)
    for x in range(n, -1, -1):
        if dp[x] <= B:
            print(f"{x} {dp[x]}")
            break
