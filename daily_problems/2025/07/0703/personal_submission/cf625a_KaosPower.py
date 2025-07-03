#  A. Guest From the Past
from typing import List
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapreplace
from itertools import pairwise, permutations, accumulate
from math import inf, comb, sqrt, ceil, floor, log, log2, log10
from functools import cache
from math import gcd
from collections import defaultdict, Counter
import io, os
import sys

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def solve():
    n = int(input())
    a = int(input())
    b = int(input())
    c = int(input())
    ans=0
    if b-c<=a:
        ans=fmax(n-c,0)//(b-c)
        n-=ans*(b-c)
    ans+=n//a
    print(ans)

solve()
