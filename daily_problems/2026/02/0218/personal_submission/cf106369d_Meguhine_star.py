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
    Y, X, R = map(int, input().split())
    X = abs(X)
    if (X * Y)**2 > R**2 * (X**2 + Y**2):
        print("-1")
    elif X <= R:
        print("0")
    else:
        A = math.atan2(Y, X)
        # B = math.pi - math.asin(X * math.sin(A) / R)
        # C = math.pi - A - B
        C = math.asin(X * math.sin(A) / R) - A
        print(f"{math.degrees(C):.8f}")


# NOTE, math.isclose default rel_tot=1e-9, TOO INACCURATE
# but if we raise to 1e-16, we don't need math.isclose at all
# so just need<=R
