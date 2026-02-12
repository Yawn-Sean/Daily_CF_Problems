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


def solve():
    n, m = map(int, input().split())
    if n & 1:  # m is even
        mid = m >> 1
        a = dict()
        for _ in range(n):
            s = tuple(map(int, input().split()))
            a[s[:mid]] = s[mid:]
        key, value = a.popitem()
        ans = [key]
        while a:
            # print(f"key={key} value={value} a={a}")
            key = value
            ans.append(key)
            value = a.pop(key)
        print(" ".join(map(str, list(chain.from_iterable(ans)))))
    else:  # n is even
        print(" ".join(set(input() for _ in range(n))))


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
