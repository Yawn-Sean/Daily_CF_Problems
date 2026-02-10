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

"""
3 ok ! (2,)
4 ok ! (3, 2)
5 ok ! (2, 4, 3)
6 Failed !
7 ok ! (2, 5, 6, 3, 4)
8 Failed !
9 Failed !
10 Failed !
11 ok ! (2, 3, 5, 10, 6, 7, 4, 9, 8)
12 Failed !
13 ok ! (2, 3, 4, 5, 6, 12, 7, 9, 10, 8, 11)
14 Failed !

mul is (1,2,3,...,n-1,0)
n=4 is special
"""


if __name__ == "__main__":
    n = int(input())
    if n == 4:
        print("1 3 2 4")
        sys.exit(0)
    x = 2
    while x * x <= n:
        if n % x == 0:
            print("-1")
            sys.exit(0)
        x += 1
    ans = [1 for _ in range(n)]
    ans[-1] = n
    fc = [1 for _ in range(n + 1)]
    for i in range(2, n):
        fc[i] = fc[i - 1] * i % n
    inv = pow(fc[n - 1], n - 2, n)
    for i in range(n - 1, 1, -1):
        inv = inv * i % n
        # print(
        #     f"i={i} inv={inv} fc={fc[i - 1]} ans={i * inv * fc[i - 1] % n}"
        # )
        ans[i - 1] = i * inv * fc[i - 2] % n
    print(' '.join(map(str, ans)))
