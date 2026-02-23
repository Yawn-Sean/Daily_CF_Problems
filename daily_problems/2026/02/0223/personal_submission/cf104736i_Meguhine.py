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


global de, outs
de = "--LOCAL_LEETCODE" in sys.argv
input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if y < x else y


MOD = 10**9 + 7


def init(s: str) -> List[int]:
    pre = [0] * 27
    for c in reversed(s):
        x = ord(c) - ord('a')
        if x:
            pre[-1] += pre[x - 1]
        for i in range(x, 26):
            pre[i] += 1
    pre[-1] %= MOD
    return pre


def concatenate(a: List[int], b: List[int]) -> List[int]:
    c = [(x + y) % MOD for x, y in zip(a, b)]
    for i in range(1, 26):
        c[-1] += (a[i] - a[i - 1]) * b[i - 1]
    c[-1] %= MOD
    return c


if __name__ == "__main__":
    s = input()
    n = int(input()) - 1
    base = init(s)
    ans = base.copy()
    while n:
        if n & 1:
            ans = concatenate(ans, base)
        base = concatenate(base, base)
        n >>= 1
    print(ans[-1])
