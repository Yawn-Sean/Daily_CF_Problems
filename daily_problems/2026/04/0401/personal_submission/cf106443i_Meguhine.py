import sys
from array import array
from collections import deque
from dataclasses import dataclass
from typing import Any, List, Optional, Tuple

input = lambda: sys.stdin.readline().rstrip()
INF = 10**16
B = 11
MASK = (1 << B) - 1


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


@dataclass(slots=True)
class SCC(Graph):

    def __init__(self, n: int) -> None:
        Graph.__init__(self, n)

    def build(self) -> array:
        """
        return an array of (n+1) elements
        the last one is total colors
        others are color of each node
        """
        n = self.n
        sys.setrecursionlimit(max(n + 1000, sys.getrecursionlimit()))

        dfn = array('i', [-1] * n)
        low = array('i', [-1] * n)
        instack = array('b', [0] * n)
        scc = array('i', [-1] * (n + 1))
        tim = col = 0
        stk = array('i', [0] * n)
        top = 0

        def tarjan(u: int) -> None:
            nonlocal tim, col, top

            low[u] = dfn[u] = tim
            tim += 1
            stk[top] = u
            instack[u] = 1
            top += 1

            for wv in self.iterate(u):  # CHECK
                v = wv & MASK           # CHECK
                if dfn[v] == -1:
                    tarjan(v)
                    low[u] = low[u] if low[u] < low[v] else low[v]
                elif instack[v]:
                    low[u] = low[u] if low[u] < low[v] else low[v]

            if dfn[u] == low[u]:
                while True:
                    top -= 1
                    v = stk[top]
                    scc[v] = col
                    instack[v] = 0
                    if v == u:
                        break
                col += 1

        for u in range(n):
            if dfn[u] == -1:
                tarjan(u)

        scc[-1] = col
        return scc


n, m = map(int, input().split())
e = SCC(n)
for _ in range(m):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    e.append(u, w << B | v)

ok = array('b', [0] * n)  # reachable
ok[0] = 1
stk = [0]
while stk:
    u = stk.pop()
    for wv in e.iterate(u):
        v = wv & MASK
        if ok[v] == 0:
            ok[v] = 1
            stk.append(v)

scc = e.build()
col = scc.pop()
gps = [[] for _ in range(col)]
for u in range(n):
    gps[scc[u]].append(u)

dp = [[-INF] * (n + 1) for _ in range(n)]
for c, gp in enumerate(gps):
    st = gp[0]
    if ok[st] == 0:
        continue
    dp[st][0] = 0
    for d in range(n):
        for u in gp:
            dis = dp[u][d]
            if dis == -INF:
                continue
            for wv in e.iterate(u):
                w, v = wv >> B, wv & MASK
                ndis = dis + w
                dp[v][d + 1] = dp[v][d + 1] if dp[v][d + 1] > ndis else ndis

ans = 0
for u in range(n):
    dis = dp[u][n]
    if dis == -INF:
        continue
    res = INF
    for d in range(0, n):
        cur = dp[u][d]
        if cur == -INF:
            continue
        x = (dis - cur) / (n - d)
        res = res if res < x else x
    ans = ans if ans > res else res

print(f"{ans:.8f}")
