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
    n = int(input())

    vs = [0] * n
    ts = [0] * n
    for i in range(n):
        v, t = map(int, input().split())
        vs[i], ts[i] = v, t

    sum_v = sum(vs)
    rest_v = sum_v
    ratio, cur, last_t = 1, 0, 0

    outs = [""] * n
    idx = sorted(range(n), key=lambda x: ts[x])
    for i in idx:
        v, t = vs[i], ts[i]

        rest = v * (t - cur)

        add_t = rest / (ratio * v)
        cur_t = last_t + add_t
        last_t = cur_t

        cur += ratio * add_t
        rest_v -= v
        if rest_v:
            ratio = sum_v / rest_v

        outs[i] = f"{cur_t:.8f}"

    print("\n".join(outs))
