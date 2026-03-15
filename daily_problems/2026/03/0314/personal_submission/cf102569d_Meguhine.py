# -*- coding: UTF-8 -*-
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


ord_a = ord('a')
B = 5
MASK = (1 << B) - 1

if __name__ == "__main__":
    n, m = map(int, input().split())

    e = Graph(n)
    for _ in range(m):
        str_u, str_v, c = input().split()
        u, v, w = int(str_u) - 1, int(str_v) - 1, ord(c) - ord_a
        e.append(u, v << B | w)
        e.append(v, u << B | w)

    dis = [0] * n
    dis[-1] = 1
    p = deque([n - 1])
    adj = Graph(n)
    while p:
        u = p.popleft()
        du = dis[u]
        for vw in e.iterate(u):
            v, w = vw >> B, vw & MASK
            if not dis[v]:
                dis[v] = dis[u] + 1
                p.append(v)
                adj.append(v, u << B | w)
            elif dis[v] == du + 1:
                adj.append(v, u << B | w)

    dn = dis[0] - 1
    p, np = [0], []
    pre = [-1] * n
    for _ in range(dn):
        mn = MASK
        for u in p:
            for vw in adj.iterate(u):
                w = vw & MASK
                if w < mn:
                    mn = w
        for u in p:
            for vw in adj.iterate(u):
                v, w = vw >> B, vw & MASK
                if w == mn and pre[v] == -1:
                    pre[v] = u << B | w
                    np.append(v)
        p, np = np, []

    str_path, str_w = [""] * (dn + 1), [""] * dn
    str_path[0] = str(n)

    u = n - 1
    for i in range(dn):
        vw = pre[u]
        v, w = vw >> B, vw & MASK
        str_path[i + 1] = str(v + 1)
        str_w[i] = chr(w + ord_a)
        u = v

    print('\n'.join((
        str(dn),
        ' '.join(reversed(str_path)),
        ''.join(reversed(str_w))
    )))
