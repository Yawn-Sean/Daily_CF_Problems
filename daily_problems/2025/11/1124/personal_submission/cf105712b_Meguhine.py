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


def solve(_case: int) -> None:
    n = int(input())
    a = list(map(int, input().split()))

    if n == 2:
        ans = 0
        while a[0] > 1 or a[1] > 1:
            x = a[0] >> 1
            a[0] -= (x << 1)
            a[1] += x
            ans += x
            x = a[1] >> 1
            a[1] -= (x << 1)
            a[0] += x
            ans += x
        outs[_case] = str(ans)
        return

    s, c1 = 0, 0
    for x in a:
        s += x
        c1 += (x == 1)

    if s == 0:
        outs[_case] = "0"
    elif c1 == 0:
        outs[_case] = "1" if s == 3 else str(s - 1)
    else:
        outs[_case] = "0" if s == c1 else str(s - 1)


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print("\n".join(outs))
