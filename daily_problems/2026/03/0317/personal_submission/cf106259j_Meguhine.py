# -*- coding: UTF-8 -*-
import sys
from array import array
from dataclasses import dataclass
from itertools import accumulate
from typing import Any

global outs
input = lambda: sys.stdin.readline().rstrip()


@dataclass(slots=True)
class DSU:
    n: int
    fa: array

    def __init__(self, n: int) -> None:
        self.n = n
        self.fa = array('i', range(n))

    def get(self, x: int) -> int:
        while x != self.fa[x]:  # DONT MERGE !!!
            self.fa[x] = self.fa[self.fa[x]]
            x = self.fa[x]
        return x

    def merge(self, x: int, y: int) -> None:
        x, y = self.get(x), self.get(y)
        if x != y:
            self.fa[x] = y
        return True


class FenwickTree:

    def __init__(self, n: int = 0) -> None:
        self._n = n
        self.data = [0] * n

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
    fen = FenwickTree(n + 1)
    for i, x in enumerate(a):
        if x == 1 or x == 2:
            nxt.merge(i, i + 1)
            fen.add(i, x)

    opt = []
    for _ in range(Q):
        op, l, r = map(int, input().split())
        l -= 1
        r -= 1
        if op == 1:
            i = nxt.get(l)
            while i <= r:
                if a[i] == 0:
                    fen.add(i, 1)
                    nxt.merge(i, i + 1)
                elif b[i]:
                    nxt.merge(i, i + 1)
                else:
                    if a[i] >= 13:
                        b[i] = 1
                    if a[i] < N:
                        a[i] = fc[a[i]]
                    else:
                        a[i] = tab[a[i]]
                i = nxt.get(i + 1)
        else:
            res = fen.sum(l, r + 1)
            i = nxt.get(l)
            while i <= r:
                res += a[i]
                i = nxt.get(i + 1)
            opt.append(str(res % MOD))

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
