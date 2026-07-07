import sys
from typing import Any, Iterable

input = lambda: sys.stdin.readline().rstrip()
MOD = 10**9 + 7


class Fenwick:

    def __init__(self, n: int = 0) -> None:
        self._n = n
        self.data = [0] * n

    def init(self, a: Iterable) -> None:
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


def solve() -> str:
    n, M = map(int, input().split())
    a = [tuple(map(int, input().split())) for _ in range(n)]
    idx = sorted(range(n), key=lambda x: a[x][0])
    fen = Fenwick(M + 1)
    ans = 0
    for i in idx:
        l, r = a[i]
        fen.add(r, l)
        ans += fen._sum(l) * (M - r + 1) % MOD
    return str(ans % MOD)


print('\n'.join(solve() for _ in range(int(input()))))
