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
from itertools import count, product, pairwise
from operator import add, iand, ior, itemgetter, mul, xor
from string import ascii_lowercase, ascii_uppercase, ascii_letters
from dataclasses import dataclass
from typing import *


@dataclass
class Vector:
    x: int | float
    y: int | float

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def dot(self, other):
        return self.x * other.x + self.y * other.y

    def cross(self, other):
        return self.x * other.y - self.y * other.x

    def norm(self):
        return math.sqrt(self.x**2 + self.y**2)

    def dis(self, other):
        return (self - other).norm()


input = lambda: sys.stdin.readline().rstrip()

if __name__ == "__main__":
    n = int(input())
    a = [Vector(*map(int, input().split())) for _ in range(n)]
    st_idx, dis = 0, 0
    for i in range(1, n):
        ndis = a[0].dis(a[i])
        if ndis > dis:
            st_idx, dis = i, ndis
    st_pt = a[st_idx]
    a.sort(key=lambda x: st_pt.dis(x))
    ans = 0
    for x, y in pairwise(a):
        ans += x.dis(y)
    print(f"{ans:.12f}")
