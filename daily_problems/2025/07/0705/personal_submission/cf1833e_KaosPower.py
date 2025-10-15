#  E. Round Dance
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


# 按秩合并,带标签和返回值的并查集,存储形式为数组,find函数用迭代实现
class UnionFind:
    def __init__(self, n):
        self.father = list(range(n))
        self.size = [1] * n
        self.cc = n

    def find(self, i):
        st = []
        while i != self.father[i]:
            st.append(i)
            i = self.father[i]
        while st:
            self.father[st.pop()] = i
        return i

    def union(self, x, y):
        fx, fy = self.find(x), self.find(y)
        if fx == fy:
            return False
        if self.size[fx] >= self.size[fy]:
            self.size[fx] += self.size[fy]
            self.father[fy] = fx
        else:
            self.size[fy] += self.size[fx]
            self.father[fx] = fy
        self.cc -= 1
        return True

    def reset(self):
        n = len(self.father)
        self.father = list(range(n))
        self.size = [1] * n
        self.cc = n
#最小值为min(环数+1,连通分量数),即将所有链并成一条链,最大值为连通分量数
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    t = UnionFind(n+1)
    g=[[] for _ in range(n+1)]
    deg=[0]*(n+1)
    vis = set()
    for u,v in enumerate(a,1):
        if u>v:
            u,v=v,u
        if (u,v) not in vis:
            deg[u]+=1
            deg[v]+=1
        vis.add((u,v))
        t.union(u,v)
    #下标从1开始,因此连通块数量要减1
    tot=t.cc-1
    cnt=deg.count(1)
    # 度数为1的点的个数除以2就代表链的个数
    # 连通分量个数-链的个数=环的个数,将所有链合成一条链,因此再+1
    # 最后要和tot取min,因为可能没有链
    print(fmin(tot-cnt//2+1,tot),tot)


t = int(input())
for i in range(t):
    solve()
