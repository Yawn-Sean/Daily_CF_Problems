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


def query(x: int, y: int) -> bool:
    print(f"? {x} {y}", flush=True)
    return input()[0] == 'b'


if __name__ == "__main__":
    n, m = map(int, input().split())
    a = list(range(1, n + 1))
    random.seed()
    random.shuffle(a)
    ansx, ansy = 1, 0
    for x in a:
        if not query(x, ansy + 1):
            continue
        ansx, ansy = x, ansy + 1
        l, r = ansy + 1, m
        while l <= r:
            mid = (l + r) // 2
            if query(x, mid):
                ansy = mid
                l = mid + 1
            else:
                r = mid - 1
        if ansy == m:
            break
    print(f"! {ansx} {ansy}")
