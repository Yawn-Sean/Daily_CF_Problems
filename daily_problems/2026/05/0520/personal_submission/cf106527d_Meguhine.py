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


n, m = map(int, input().split())
d = int(input()[0])

e = Graph(n + 1)
deg = [0] * (n + 1)
for _ in range(m):
    u, v = map(int, input().split())
    e.append(u, v)
    deg[v] += 1

p = deque([u for u in range(1, n + 1) if deg[u] == 0])
dp = [0] * (n + 1)
while p:
    u = p.popleft()
    for v in e.iterate(u):
        deg[v] -= 1
        dp[v] = max(dp[v], dp[u] + 1)
        if dp[v] == 67:
            print("NO")
            sys.exit(0)
        if deg[v] == 0:
            p.append(v)

if max(deg) != 0:
    print("NO")
else:
    print("YES")
    print('\n'.join(str(d) * m))

"""
首先, 不能有任何的环(包括自环), 不然绕这个环走67圈, 一定会FAIL
现在这个图一定是DAG, 我们来考虑最长**路径**的长度
显然<=66, 因为记录[前缀和%67], 应用抽屉原理即可
现在这是个深度很浅的DAG, 那我们该怎么赋值呢?
因为67是一个质数, 所以给每条边赋上相同的值即可
"""
