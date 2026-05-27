import sys
from array import array
from dataclasses import dataclass
from itertools import islice
from typing import Any, List

input = lambda: sys.stdin.readline().rstrip()


@dataclass(slots=True)
class Graph:
    n: int
    pre: array
    val: List[Any]
    head: array

    def __init__(self, n: int) -> None:
        self.n = n
        self.pre = array('i')
        self.val = []
        self.head = array('i', [-1] * (n + 1))

    def append(self, i: int, j: Any) -> None:
        self.pre.append(self.head[i])
        self.head[i] = len(self.val)
        self.val.append(j)

    def iterate(self, i: int) -> Any:
        tmp = self.head[i]
        while tmp != -1:
            yield self.val[tmp]
            tmp = self.pre[tmp]


INF = 10**18
B = 10
MASK = (1 << B) - 1


def solve() -> str:
    n, m = map(int, input().split())
    e = Graph(n)
    for _ in range(m):
        u, v, w = map(int, input().split())
        e.append(u, w << B | v)
    L = min(n, m + 1)  # layer, 最长的路径可能的长度
    dp = [[INF] * n for _ in range(L)]
    for i in range(L):
        dp[i][0] = 0
    for l in range(L - 1, 0, -1):
        nw = dp[l - 1]
        for u, du in enumerate(dp[l]):
            for wv in e.iterate(u):
                w, v = wv >> B, wv & MASK
                nw[v] = min(nw[v], du + w * l)
    return ' '.join(
        "-1" if d == INF else str(d) for d in islice(dp[0], 1, n)
    )


print('\n'.join(
    solve() for _ in range(int(input()))
))
