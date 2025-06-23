from typing import List
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapreplace
from itertools import pairwise, permutations, accumulate
from math import inf, comb, sqrt, ceil, floor, log, log2, log10
from functools import cache
from math import gcd
from collections import defaultdict

Max = lambda x, y: x if x > y else y
Min = lambda x, y: x if x < y else y


def solve():
    s=input()
    k = int(input())
    #1表示向前,0表示向后
    s=[1 if x=='F' else 0 for x in s]
    #i表示下标,k表示剩余修改次数,d表示当前方向
    @cache
    def f1(i,k,d):
        if i==-1:
            return 0 if k==0 else -inf
        ans=-inf
        for j in range(k+1):
            v=s[i]^(j&1)
            ans=max(ans,f1(i-1,k-j,d if v else -d)+d*v)
        return ans
    ans=f1(len(s)-1,k,1)
    f1.cache_clear()
    @cache
    def f2(i, k, d):
        if i == -1:
            return 0 if k == 0 else inf
        ans = inf
        for j in range(k + 1):
            v = s[i] ^ (j & 1)
            ans = min(ans, f2(i - 1, k - j, d if v else -d) + d * v)
        return ans
    ans = max(ans,-f2(len(s) - 1, k, 1))
    f2.cache_clear()
    print(ans)
solve()
