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


# pigeonhole principle
def solve(_case: int) -> None:
    n = int(input())
    a = list(map(int, input().split()))
    idx = list(range(n))
    ans = [""] * (n - 1)
    for m in range(n - 1, 0, -1):
        mp = [-1] * m
        for _, i in enumerate(idx):
            r = a[i] % m
            if mp[r] == -1:
                mp[r] = i
            else:
                ans[m - 1] = f"{mp[r] + 1} {i + 1}"
                idx.pop(_)
                break
    outs[_case] = f"YES\n{idx[0] + 1}\n" + '\n'.join(ans)


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print("\n".join(outs))
