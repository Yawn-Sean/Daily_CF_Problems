# -*- coding: UTF-8 -*-
import sys
from array import array
from dataclasses import dataclass
from itertools import accumulate
from typing import Any, List, Optional

global outs
input = lambda: sys.stdin.readline().rstrip()


class Fenwick:

    def __init__(self, n: int = 0) -> None:
        self._n = n
        self.data = [0] * n

    def init(self, a: List | array) -> None:
        for i, x in enumerate(a, 1):
            if i >= self._n:
                break
            self.data[i - 1] += x
            j = i + (i & -i)
            if j <= self._n:
                self.data[j - 1] += self.data[i - 1]

    def add(self, p: int, x: Any) -> None:
        assert 0 <= p < self._n

        p += 1
        while p <= self._n:
            self.data[p - 1] += x
            p += p & -p

    # [l, r - 1]
    def sum(self, left: int, right: int) -> Any:
        assert 0 <= left <= right <= self._n

        return self._sum(right) - self._sum(left)

    # [0, r - 1]
    def _sum(self, r: int) -> Any:
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r

        return s


@dataclass(slots=True)
class DSU:
    n: int
    fa: array
    sz: array
    head: array

    def __init__(self, n: int) -> None:
        self.n = n
        self.fa = array('i', range(n))
        self.sz = array('i', [1] * n)
        self.head = array('i', range(n))

    def get(self, x: int) -> int:
        while x != self.fa[x]:  # DONT MERGE !!!
            self.fa[x] = self.fa[self.fa[x]]
            x = self.fa[x]
        return x

    def H(self, x: int) -> int:
        return self.head[self.get(x)]

    def same(self, x: int, y: int) -> bool:
        return self.get(x) == self.get(y)

    def merge(self, x: int, y: int) -> bool:
        x, y = self.get(x), self.get(y)
        if x == y:
            return False
        top = self.head[y]
        if self.sz[y] < self.sz[x]:
            x, y = y, x
        self.sz[y] += self.sz[x]
        self.fa[x] = y
        self.head[x] = self.head[y] = top
        return True

    def size(self, x: int) -> int:
        return self.sz[self.get(x)]


MOD = 998244353  # fac(13) > 998244353
N = 5 * 10**5 + 5
fc = list(accumulate(
    range(1, N),
    lambda acc, x: acc * x % MOD,
    initial=1
))
tab = {3628800: 821984089, 39916800: 644056242, 479001600: 527656359}


def solve(_case: int) -> None:
    n, Q = map(int, input().split())
    a = list(map(int, input().split()))
    b = [0] * n

    nxt = DSU(n + 1)
    fen = Fenwick(n + 1)
    fen.init(a)
    for i, x in enumerate(a):
        if x == 1 or x == 2:
            nxt.merge(i, i + 1)

    opt = []
    for _ in range(Q):
        op, l, r = map(int, input().split())
        l -= 1
        r -= 1
        if op == 1:
            i = nxt.H(l)
            while i <= r:
                x = a[i]
                if x == 0:
                    fen.add(i, 1)
                    nxt.merge(i, i + 1)
                elif b[i]:
                    fen.add(i, -x)
                    nxt.merge(i, i + 1)
                else:
                    if x >= 13:
                        b[i] = 1
                    a[i] = fc[x] if x < N else tab[x]
                    fen.add(i, a[i] - x)
                i = nxt.H(i + 1)
        else:
            opt.append(str(fen.sum(l, r + 1) % MOD))

    outs[_case] = '\n'.join(opt)


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print('\n'.join(outs))


"""
from math import factorial as fac

MOD = 998244353
idx = (fac(10), fac(11), fac(12))
tab = {}
res = 1
for x in range(2, idx[-1] + 1):
    res = res * x % MOD
    if x in idx:
        tab[x] = res
print(f"{tab=}")
"""
