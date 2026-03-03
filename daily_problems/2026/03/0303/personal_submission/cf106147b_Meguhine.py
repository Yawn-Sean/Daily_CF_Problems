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
# input = lambda: sys.stdin.readline().rstrip()
fmin = lambda x, y: x if x < y else y
fmax = lambda x, y: x if y < x else y


N = 3 * 10**4
# mp = {}
mp = defaultdict(list)
bases = (2, 3, 5, 7)
M = len(bases)
str_bases = [""] * M

if 1:
    # base_cnt = 0  #
    for i, base in enumerate(bases):
        opt = [1]
        x = base
        # base_cnt += 1  #
        while x < N:
            # base_cnt += 1  #
            opt.append(x)
            x *= base
        str_bases[i] = str(len(opt)) + ' ' + ' '.join(map(str, opt))
    # print(f"{base_cnt=}")  #
    # print(str_bases)  #

    # max_cnt_sum = 0  #
    for x in range(1, N + 1):
        opt = 0
        # cnt_sum = 0  #
        for base in bases:
            cnt = 0
            X = x
            while X:
                cnt += X % base
                X //= base
            opt = opt * 100 + cnt
            # cnt_sum += cnt  #
        # max_cnt_sum = fmax(max_cnt_sum cnt_sum)  #
        mp[opt].append(x)
        # assert opt not in mp
        # mp[opt] = x
    # print(f"{max_cnt_sum=}")  #
    # print(mp)  #
    # print(f"{max(map(len, mp.values()))=}")  #


if __name__ == "__main__":
    opt = 0
    for i in range(M):
        print(f"? {str_bases[i]}", flush=True)
        opt = opt * 100 + int(input())

    vec = mp[opt].copy()
    qry_base = [(1 << x) for x in range(15)]
    while len(vec) > 1:
        random.shuffle(vec)
        p = (len(vec) + 1) // 2
        qry = qry_base + vec[:p]
        print(f"? {len(qry)} {' '.join(map(str, qry))}", flush=True)
        if int(input()) == 1:
            vec = vec[:p]
        else:
            vec = vec[p:]

    print(f"! {vec[0]}", flush=True)
