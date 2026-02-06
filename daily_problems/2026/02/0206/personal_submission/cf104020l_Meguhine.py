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

if __name__ == "__main__":
    n = int(input())
    a = []
    for _ in range(n):
        a.append(tuple(map(int, input().split())))
    a.sort()
    ans = 1e18
    for i in range(n):
        for j in range(i + 1, n):
            if j - i > 200:
                break
            dx, dy, dz = a[j][0] - a[i][0], a[j][1] - \
                a[i][1], a[j][2] - a[i][2]
            ans = min(ans, math.sqrt(dx**2 + dy**2 + dz**2))
    print('{:.6f}'.format(ans))
