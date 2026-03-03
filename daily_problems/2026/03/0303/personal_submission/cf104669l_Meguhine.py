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


N = 2 * 10**5 + 5


def solve(_case: int) -> None:
    L, LEN = map(int, input().split())
    R = L + LEN - 1
    S = (L + R) * LEN // 2
    # print(f"{S=}")  #

    a = [[L, R]]
    for x in range(2, LEN + 1):
        off = x * (x - 1) // 2
        l = x * L + off
        r = x * R - off
        if a[-1][1] + 1 >= l:
            a[-1][1] = r
        else:
            a.append([l, r])
    a[-1][1] -= 1
    # print(a)  #
    # print(f"{len(a)=}")  #
    # a.append([10**18, 10**18])
    # m = len(a)

    ans = 1

    def check(x: int) -> None:
        nonlocal ans
        for rg in a:
            l, r = rg[0], rg[1]
            l = (l - 1) // x + 1
            r //= x
            if l <= r:
                ans = x
                return
        # p = bisect.bisect_right(
        #     range(m), x, key=lambda x: a[x][0]
        # ) - 1
        # if a[p][0] <= x <= a[p][1]:
        #     ans = fmax(ans, x)

    for x in range(2, N):
        if x * x > S:
            break
        if S % x:
            continue
        if x > ans:
            check(x)
        x = S // x
        if x > ans:
            check(x)
    outs[_case] = str(ans)


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print("\n".join(outs))
