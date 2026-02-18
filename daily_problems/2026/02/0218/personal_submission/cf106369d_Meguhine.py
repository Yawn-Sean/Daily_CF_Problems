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
    A = math.atan2(X, Y)
    B = math.pi / 2 - A
    XB = X * math.sin(B)
    l, r, ans = 0, A, -1
    for _ in range(60):
        mid = (l + r) / 2
        C = math.pi - mid - B
        # sine theory, X/sin(C) == need/sin(B)
        need = XB / math.sin(C)
        if need <= R:  # or math.isclose(need, R, rel_tol=1e-16):
            ans = r = mid
        else:
            l = mid

    if ans == -1:
        print("-1")
    else:
        print(f"{math.degrees(ans):.8f}")


# NOTE, math.isclose default rel_tot=1e-9, TOO INACCURATE
# but if we raise to 1e-16, we don't need math.isclose at all
# so just need<=R
