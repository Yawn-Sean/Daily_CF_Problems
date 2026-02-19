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
    n, l, r, k = map(int, input().split())
    a = list(map(int, input().split()))

    if k >= min(a):
        print("-1")
        sys.exit(0)
    if l <= k <= r:
        print(k)
        sys.exit(0)

    lcm = a[0]
    for x in a:
        lcm = math.lcm(lcm, x)
        if lcm + k > r:
            print("-1")
            sys.exit(0)

    mul = (l - k - 1) // lcm + 1
    # print(f"{lcm=} {k=} {mul=}")
    ans = k + mul * lcm
    if l <= ans <= r:
        print(ans)
    else:
        print("-1")
