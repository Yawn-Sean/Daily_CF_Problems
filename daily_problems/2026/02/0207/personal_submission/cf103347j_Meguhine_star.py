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

"""
k * (x**k) == y (mod p), 1<=k<=a
p is prime, p<=(10**6)+3
iterate over k to get {(x**k)%p}
l := repretend len == p-1
#i := [(k+i*l <= a) and (k+i*l) * xk == y]
k+i*l == y * pow(xk,p-2,p)
i == (y * pow(xk,p-2,p) - k) * pow(l,p-2,p)
available: i, i+p, i+2p, ...
k+(i+q*p)*l<=a
q<=((a-k)/l-i)/p
"""

if __name__ == "__main__":
    p, x, y, a = map(int, input().split())
    l = p - 1  # len(repretend), constant for specific prime
    inv_l = pow(l, p - 2, p)
    inv_x = pow(x, p - 2, p)
    k, inv_xk = 1, inv_x
    ans = 0
    while k <= min(a, l):
        i = ((y * inv_xk % p - k + p) % p) * inv_l % p
        q = ((a - k) // l - i) // p
        if q >= 0:
            ans += q + 1
        k += 1
        inv_xk = inv_xk * inv_x % p
    print(ans)
