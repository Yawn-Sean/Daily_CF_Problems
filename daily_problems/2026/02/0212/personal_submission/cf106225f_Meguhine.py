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


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n - 1, 0, -1):
        if a[i - 1] >= a[i]:
            x = a[i]
            y = a[i - 1] // (x - 1)
            # assert (x - 1) * y == a[i - 1]
            # assert y >= x
            print(y)
            return
    d = a[-1] - a[-2]
    ans = fmax(a[-1] // d, d)
    print(ans)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
