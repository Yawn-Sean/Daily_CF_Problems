import os
import random
import sys
from collections import defaultdict, Counter, deque
from functools import cache, reduce
from itertools import pairwise, combinations, permutations, groupby
from bisect import bisect_left, bisect_right, insort_left, insort_right
from operator import *

input = sys.stdin.readline
output = lambda x: sys.stdout.write(x + "\n")

I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(MII())
TMII = lambda: tuple(MII())
LI = lambda: input().split()


class UnionFind:
    def __init__(self, n: int):
        self.parents = list(range(n))

    def find(self, index: int) -> int:
        if index == self.parents[index]:
            return index
        self.parents[index] = self.find(self.parents[index])
        return self.parents[index]

    def union(self, index1: int, index2: int) -> None:
        self.parents[self.find(index1)] = self.find(index2)


def solve():
    _ = I()
    n, k = MII()
    mines = list()
    for _ in range(n):
        mines.append(TMII())
    uf = UnionFind(n)
    indices = {(pos[0], pos[1]): i for i, pos in enumerate(mines)}
    _x = defaultdict(list)
    _y = defaultdict(list)
    for x, y, t in mines:
        _x[x].append(y)
        _y[y].append(x)
    for x, ys in _x.items():
        ys.sort()
        length = len(ys)
        right = 0
        for left, y in enumerate(ys):
            while right < length and ys[right] <= y + k:
                uf.union(indices[((x, ys[left]))], indices[((x, ys[right]))])
                right += 1
    for y, xs in _y.items():
        xs.sort()
        length = len(xs)
        right = 0
        for left, x in enumerate(xs):
            while right < length and xs[right] <= x + k:
                uf.union(indices[((xs[left]), y)], indices[((xs[right]), y)])
                right += 1
    time = defaultdict(lambda: float("inf"))
    for i in range(n):
        time[uf.find(i)] = min(time[uf.find(i)], mines[i][2])
    det = sorted(time.values())
    def check(t):
        i = bisect_left(det, t + 1)
        return len(det) - i <= t + 1
    ans = bisect_left(range(n + 1), True, key=check)
    output(str(ans))




TC = II()

def main():
    for _ in range(TC):
        solve()

main()
