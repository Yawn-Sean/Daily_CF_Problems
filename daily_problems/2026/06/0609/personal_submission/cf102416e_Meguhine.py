import sys
from array import array
from collections import deque
from dataclasses import dataclass
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


n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
e = Graph(n)
deg = array('b', [0] * n)
for i in range(n):
    xi, yi, zi, ri = a[i]
    for j in range(i):
        xj, yj, zj, rj = a[j]
        if (xi - xj)**2 + (yi - yj)**2 + (zi - zj)**2 < (ri + rj)**2:
            if ri > rj:
                e.append(i, j)
                deg[j] += 1
            elif rj > ri:
                e.append(j, i)
                deg[i] += 1
            else:
                e.append(i, j)
                e.append(j, i)


vis = array('b', [0] * n)
ans = []
while True:
    u = -1
    for i in range(n):
        if deg[i] <= 0 and vis[i] == 0:
            u = i
            break
    else:
        break
    vis[u] = 1
    ans.append(u + 1)
    for v in e.iterate(u):
        vis[v] = 1
        for w in e.iterate(v):
            deg[w] -= 1
print(len(ans))
print(' '.join(map(str, ans)))


"""
建图然后贪心构造极大独立集即可
"""
