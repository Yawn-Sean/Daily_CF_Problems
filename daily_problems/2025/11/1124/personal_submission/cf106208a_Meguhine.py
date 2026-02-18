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


global de
global outs
de = "--LOCAL_LEETCODE" in sys.argv
input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if y < x else y


global MOD
global inv2
global C
if 1:
    M = 2 * 10**6 + 5
    N = 2 * 10**6
    MOD = 998244353
    inv2 = pow(2, MOD - 2, MOD)

    fc = [1] * M
    inv = [1] * M
    for x in range(2, M):
        fc[x] = fc[x - 1] * x % MOD
    tmp = pow(fc[M - 1], MOD - 2, MOD)
    for x in range(M - 1, 1, -1):
        inv[x] = tmp * fc[x - 1] % MOD
        tmp = tmp * x % MOD

    C = [0] * M
    S = [0] * M
    Z = [0] * M
    for x in range(1, N + 1):
        C[x] = (1 + Z[x] * inv[x] % MOD * inv[x + 3] * 2) % MOD
        S[x] = (S[x - 1] + C[x]) % MOD
        Z[x + 1] = (Z[x] + S[x - 1] + C[x] * 2) % MOD


def solve(_case: int) -> None:
    l, r = map(int, input().split())
    ans = (l + r) * inv2 * (C[r - l] + 1) % MOD
    outs[_case] = str(ans)


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print("\n".join(outs))
