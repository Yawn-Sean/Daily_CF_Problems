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
    n = int(input())
    if n == 1:
        print("1")
        sys.exit(0)
    if (n & 3) == 3:
        print("-1")
        sys.exit(0)
    a = [i for i in range(1, n + 1)]
    for i in range(3, n, 4):
        a[i - 1], a[i] = a[i], a[i - 1]
    print(' '.join(map(str, a)))
    if de:
        s = 0
        for i, x in enumerate(a):
            s ^= x
            print(f"a[{i}]={x} s={s}")
            assert s != 0
