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


if __name__ == "__main__":
    n, time_save, time_recover = map(int, input().split())
    p = float(input())  # prob crash
    add_base = p * time_recover + 1
    inv_q = 1 / (1 - p)
    exp = list(accumulate(
        range(n + 1),
        lambda pre, _: (pre + add_base) * inv_q,
        initial=0
    ))
    dp = [float(0) for _ in range(n + 1)]
    for i in range(1, n + 1):
        dp[i] = min(
            dp[j] + exp[i - j] for j in range(i)
        ) + time_save
    print(f"{dp[n]:.10f}")
