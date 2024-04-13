# -*- coding : utf-8 -*-
import typing


class FenwickTree:
    """
    Reference: https://en.wikipedia.org/wiki/Fenwick_tree
    https://github.com/atcoder/ac-library/blob/master/document_en/fenwicktree.md
    """

    def __init__(self, n: int = 0) -> None:
        self._n = n
        self.data = [0] * n

    def add(self, p: int, x: typing.Any) -> None:
        assert 0 <= p < self._n

        p += 1
        while p <= self._n:
            self.data[p - 1] += x
            p += p & -p

    def sum(self, left: int, right: int) -> typing.Any:
        assert 0 <= left <= right <= self._n

        return self._sum(right) - self._sum(left)

    def _sum(self, r: int) -> typing.Any:
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r

        return s


import sys
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n = I()
nums = LI()
# vi = [(v, i) for i, v in enumerate(nums)]
# vi.sort()
# print(vi)
g = defaultdict(list)
for i, v in enumerate(nums):
    g[v].append(i)

ii = []
for v in sorted(g.keys()):
    if ii:
        i = ii[-1]
        for x in g[v]:
            if x > i:
                ii.append(x)
        for x in g[v]:
            if x < i:
                ii.append(x)
    else:
        ii.extend(g[v])

fen = FenwickTree(n)
for i in range(n):
    fen.add(i, 1)

ans = fen.sum(0, ii[0])
i1 = ii[0]
fen.add(i1, -1)
for i2 in ii[1:]:
    if i1 < i2:
        ans += fen.sum(i1, i2)
    else:
        ans += fen.sum(i1, n)
        ans += fen.sum(0, i2)
    fen.add(i2, -1)
    i1 = i2
print(ans + n)
