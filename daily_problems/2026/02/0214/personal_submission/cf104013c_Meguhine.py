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


def myswap(x: int, y: int) -> None:
    print(f"{x} {y}", flush=True)
    s = input()
    if (s[0] == 'W'):
        sys.exit(0)


if __name__ == "__main__":
    n = int(input())
    i, ai, tot = 1, 1, 0
    while True:
        tot += 1
        if tot > n * 2 - 3:
            myswap(1, 2)
            if tot == n * 2:
                i, ai, tot = 1, 1, 0
            continue
        myswap(i, i + 1)
        i += ai
        if i == n:
            i, ai = n - 2, -1
