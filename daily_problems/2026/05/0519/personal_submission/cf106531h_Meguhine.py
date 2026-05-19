import sys
from array import array
from collections import deque
from dataclasses import dataclass
from typing import Any, List, Optional, Tuple

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

    def neighbors(self, i: int) -> List[Any]:
        res = []
        tmp = self.head[i]
        while tmp != -1:
            res.append(self.val[tmp])
            tmp = self.pre[tmp]
        return res

    def iterate(self, i: int) -> Any:
        tmp = self.head[i]
        while tmp != -1:
            yield self.val[tmp]
            tmp = self.pre[tmp]

    def pop(self, i: int) -> Optional[Tuple]:
        tmp = self.head[i]
        if tmp == -1:
            return None
        ret = self.val[tmp]
        self.head[i] = self.pre[tmp]
        return (ret, tmp)


n, M = map(int, input().split())

e = Graph(n + 1)
deg = [0] * (n + 1)
for _ in range(M):
    u, v = map(int, input().split())
    e.append(u, v)
    deg[v] += 1

K = int(input())
banned = Graph(n + 1)
for _ in range(K):
    t, u = map(int, input().split())
    banned.append(u, t)

p = deque([u for u in range(1, n + 1) if deg[u] == 0])
dp = [1] * (n + 1)
while p:
    u = p.popleft()
    s = set(banned.neighbors(u))
    while dp[u] in s:
        dp[u] += 1
    for v in e.iterate(u):
        deg[v] -= 1
        dp[v] = max(dp[v], dp[u] + 1)
        if deg[v] == 0:
            p.append(v)

print("-1" if max(deg) != 0 else max(dp))
