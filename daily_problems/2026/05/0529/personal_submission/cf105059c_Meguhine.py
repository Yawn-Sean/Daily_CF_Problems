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

    def iterate(self, i: int) -> Any:
        tmp = self.head[i]
        while tmp != -1:
            yield self.val[tmp]
            tmp = self.pre[tmp]


n, m, g = map(int, input().split())
if g != 2:
    print("0")
    exit(0)
e = Graph(n + 1)
for _ in range(m):
    u, v = map(int, input().split())
    e.append(u, v)
    e.append(v, u)
d = array('b', [-1] * (n + 1))
d[1] = 0
p = deque([1])
while p:
    u = p.popleft()
    for v in e.iterate(u):
        if d[v] == -1:
            d[v] = d[u] ^ 1
            p.append(v)
        elif d[u] == d[v]:
            print("0")
            exit(0)
print(d[n])


"""
当 g 是奇数的时候, 考虑任意一条 1->n 的路径, 往返 g 次, 最后剩余的一定是 0
当 g 是偶数的时候, 此时只有 g = 2
- 如果 1->n 的路径长度为偶数, 那么答案为 0
- 否则如果图中有奇环, 那么答案为 0
- 否则答案为 1
也就是, 当 g=2 且 1->n 的路径长度为奇数 且 图为二分图, 那么答案为 1
否则答案为 0
"""
