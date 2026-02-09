# -*- coding: UTF-8 -*-
import io
import os
import sys
from io import BytesIO, IOBase
import random
import bisect
import math
from fractions import Fraction
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
from typing import __all__


@dataclass
class Vector:
    x: int | float | Fraction
    y: int | float | Fraction

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def __mul__(self, k):
        return Vector(self.x * k, self.y * k)

    def __rmul__(self, k):
        return Vector(self.x * k, self.y * k)

    def __truediv__(self, k):
        return Vector(self.x / k, self.y / k)

    def dot(self, other):
        return self.x * other.x + self.y * other.y

    def cross(self, other):
        return self.x * other.y - self.y * other.x

    def norm(self):  # use math.hypot for high accuracy
        return math.sqrt(self.x**2 + self.y**2)

    def dis(self, other):
        return (self - other).norm()

    def norm_square(self):  # faster for sorting int
        return self.x * self.x + self.y * self.y

    def dis_square(self, other):  # faster for sorting int
        return (self - other).norm_square()


input = lambda: sys.stdin.readline().rstrip()

if __name__ == "__main__":
    n = int(input())
    a = [Vector(*map(int, input().split())) for _ in range(n)]
    st = a[max(range(1, n), key=lambda i: a[0].dis_square(a[i]), default=0)]
    a.sort(key=st.dis_square)
    ans = sum(x.dis(y) for x, y in pairwise(a))
    print(f"{ans:.12f}")
