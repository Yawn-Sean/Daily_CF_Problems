# -*- coding: UTF-8 -*-
import io
import os
import sys
from io import BytesIO, IOBase
import random
import bisect
import math
from collections import Counter, defaultdict, deque
from copy import deepcopy
from functools import cmp_to_key, lru_cache, reduce
from heapq import merge, heapify, heappop, heappush, heappushpop
from heapq import nlargest, nsmallest, heapreplace
from itertools import accumulate, combinations, permutations
from itertools import count, product
from operator import add, iand, ior, itemgetter, mul, xor
from string import ascii_lowercase, ascii_uppercase, ascii_letters
import typing
from typing import *


input = lambda: sys.stdin.readline().rstrip()


if __name__ == "__main__":
    n = int(input())
    mod = 10**9 + 7
    base = pow(2, n - 1, mod)
    mp = [0 for _ in range(8)]
    for a, b, c in product([0, 1], repeat=3):
        idx = a * 4 + b * 2 + c
        if a > b:
            continue
        if a == b:
            if a == 0:  # a=0, b=0
                if c == 0:
                    mp[idx] = 1
                else:
                    continue
            else:  # a=1, b=1
                if c == (n & 1):
                    mp[idx] = 1
                else:
                    continue
        else:  # a=0, b=1
            if c == 0:
                mp[idx] = base - 1 - ((n & 1) ^ 1)
            else:
                mp[idx] = base - (n & 1)
    _a = input()
    _b = input()
    _c = input()
    ans = 1
    for a, b, c in zip(_a, _b, _c):
        idx = int(a) * 4 + int(b) * 2 + int(c)
        ans = ans * mp[idx] % mod
    print(ans)
