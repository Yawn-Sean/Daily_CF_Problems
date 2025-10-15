from typing import List
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapreplace
from itertools import pairwise, permutations, accumulate
from math import inf, comb, sqrt, ceil, floor, log, log2, log10
from functools import cache
from math import gcd
from collections import defaultdict,Counter
import io, os
import sys

Max = lambda x, y: x if x > y else y
Min = lambda x, y: x if x < y else y
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    #将原数组映射到0,1,2,3,4,3,2,1,0
    #如果做差大于0,加入哈希表
    #实际实现时,不需要构造数组,直接求min(i,n-1-i)即可
    d=defaultdict(int)
    for i,x in enumerate(a):
        v=x-Min(i,n-1-i)
        if v>0:
            d[v]+=1
    print(n-max(d.values()))
solve()
