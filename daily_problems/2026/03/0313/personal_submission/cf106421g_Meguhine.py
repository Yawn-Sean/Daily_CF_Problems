# -*- coding: UTF-8 -*-
import sys
from itertools import accumulate
from typing import Any, List

input = lambda: sys.stdin.readline().rstrip()


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


def work(a: List[int]) -> int:
    b = sorted(set(accumulate(a, initial=0)))
    mp = {x: i for i, x in enumerate(b)}
    s, res, fen = 0, 0, FenwickTree(len(b) + 5)
    fen.add(mp[0], 1)
    for x in a:
        s += x
        disc_s = mp[s]
        res += fen._sum(disc_s)
        fen.add(disc_s, 1)
    return res


if __name__ == "__main__":
    n, A, B = map(int, input().split())
    a = list(map(int, input().split()))
    a1 = list(map(lambda x: A - x, a))
    a2 = list(map(lambda x: x - B, a))
    ans = n * (n + 1) // 2 - work(a1) - work(a2)
    print(ans)
