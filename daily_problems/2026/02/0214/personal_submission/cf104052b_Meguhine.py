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
from itertools import count, product, pairwise, chain
from operator import add, iand, ior, itemgetter, mul, xor
from string import ascii_lowercase, ascii_uppercase, ascii_letters
from dataclasses import dataclass
from typing import *


global de
de = "--LOCAL_LEETCODE" in sys.argv
input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if y < x else y


global outs


def solve(_case: int):
    a, b, c, d = map(int, input().split())

    def check(S: int) -> bool:
        y = fmax(0, S - b)
        x = a - (S + y)
        z = fmin(c - (S + y), d)
        return (x >= 0 and z >= 0 and x + y + z >= S)

    l, r, ans = 1, a + b + c + d, 0
    while l <= r:
        S = (l + r) >> 1
        if check(S):
            ans = S
            l = S + 1
        else:
            r = S - 1

    outs[_case] = str(ans)


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print("\n".join(outs))
