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
    n = int(input())

    if n == 1:
        print("1\n1")
        sys.exit(0)
    if n == 2:
        print("-1")
        sys.exit(0)

    x = 2**(n - 2) * 3
    div, outs = 1, [""] * n
    for i in range(n - 2):
        div <<= 1
        outs[i] = str(x // div)
    div *= 3
    outs[-1] = str(x // div)
    div >>= 1
    outs[-2] = str(x // div)

    print(f"{x}\n{' '.join(outs)}")
    # assert (sum(map(int, outs)) == x)
