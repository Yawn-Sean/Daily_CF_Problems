# -*- coding: UTF-8 -*-
from types import GeneratorType
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
global outs
de = "--LOCAL_LEETCODE" in sys.argv
input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if y < x else y


mod = 10**9 + 7


def bootstrap(f, stk=[]):
    def wrappedfunc(*args, **kwargs):
        if stk:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stk.append(to)
                    to = next(to)
                else:
                    stk.pop()
                    if not stk:
                        break
                    to = stk[-1].send(to)
            return to
    return wrappedfunc


def solve(_case: int) -> None:
    n = int(input())
    e = [
        list(map(lambda x: int(x) - 1, input().split()))
        for _ in range(n)
    ]
    dp = array('q', [0] * n)

    @bootstrap
    def dfs(u: int):
        res = 1
        if e[u][0] == -1:
            dp[u] = 1
            yield 1
        for v in e[u]:
            tmp = yield dfs(v)
            res += tmp + 1
        dp[u] = res
        yield res
    dfs(0)

    ans = array('q', [0] * n)

    @bootstrap
    def calc(u: int, o: int):
        res = dp[u] + o
        if e[u][0] == -1:
            ans[u] = res
            yield 0
        for v in e[u]:
            yield calc(v, res)
        ans[u] = res
        yield 0

    calc(0, 0)
    outs[_case] = " ".join(map(lambda x: str(x % mod), ans))


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print("\n".join(outs))
