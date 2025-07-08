#  D. Game
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

def solve():
    n = int(input())
    a = list(map(int,input()))
    # dp解法
    # f0,f1=a[0],1-a[0]
    # for i in range(1,n):
    #     f0,f1=f1+a[i],f0+1-a[i]
    # print(fmin(f0,f1))
    # 贪心解法
    ans=sum(int(x)^i&1 for i,x in enumerate(a))
    print(fmin(ans,n-ans))
solve()
