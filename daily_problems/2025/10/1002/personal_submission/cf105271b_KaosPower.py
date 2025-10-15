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

def q(i,x):
    print('?',i+1,x,flush=True)
    return int(input()=='<')

def f(ans):
    print('!',*ans)

n=int(input())
ans=[0]*n
cur=1
for i in range(n):
    while q(i,cur):
        cur+=1
    ans[i]=cur
f(ans)
