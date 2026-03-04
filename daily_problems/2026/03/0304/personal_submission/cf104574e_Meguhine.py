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


global outs
de = "--LOCAL_LEETCODE" in sys.argv
input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if y < x else y


if __name__ == "__main__":
    _a = tuple(map(int, input().split()))

    def f(a: List[int]) -> int:
        assert len(a) == 4
        opt = 0
        for x in a:
            opt = opt << 6 | x
        return opt

    mp = [0] + [x * 2 - 1 for x in range(1, 27)] + [x * 2 for x in range(1, 27)]
    a = [i for i, x in enumerate(_a, 1) if x == 1]
    b = set()

    while True:
        if max(a) <= 26:
            print("YES")
            break

        opt = f(a)
        if opt in b:
            print("NO")
            break
        else:
            b.add(opt)

        for i, x in enumerate(a):
            a[i] = mp[x]
