
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
    if n==1:
        exit(print('N'))
    a=[]
    for i in range(2,1_000_000+1):
        if n%i==0:
            a.append(0)
            while n%i==0:
                a[-1]+=1
                n//=i
    if n>1:
        a.append(1)
    if len(a)>2:
        print('N')
    elif len(a)==1:
        print('NY'[a[0]&1])
    elif max(a)==1:
        print('Y')
    else:
        print('N')

solve()
