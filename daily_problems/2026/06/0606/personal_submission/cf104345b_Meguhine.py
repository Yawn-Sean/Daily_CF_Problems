import sys
from array import array
from dataclasses import dataclass
from types import GeneratorType
from typing import Any, List

input = lambda: sys.stdin.readline().rstrip()


def bootstrap(f, stk=[]):
    def wrappedfunc(*args, **kwargs):
        if stk:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stk.append(to)
                    to = next(to)
                else:
                    stk.pop()
                    if not stk:
                        break
                    to = stk[-1].send(to)
            return to
    return wrappedfunc


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


@dataclass(slots=True)
class DSU:
    n: int
    fa: array
    sz: array

    def __init__(self, n: int) -> None:
        self.n = n
        self.fa = array('i', range(n))
        self.sz = array('i', [1] * n)

    def get(self, x: int) -> int:
        while x != self.fa[x]:  # DONT MERGE !!!
            self.fa[x] = self.fa[self.fa[x]]
            x = self.fa[x]
        return x

    def same(self, x: int, y: int) -> bool:
        return self.get(x) == self.get(y)

    def merge(self, x: int, y: int) -> bool:
        x, y = self.get(x), self.get(y)
        if x == y:
            return False
        if self.sz[x] < self.sz[y]:
            x, y = y, x
        self.sz[x] += self.sz[y]
        self.fa[y] = x
        return True

    def size(self, x: int) -> int:
        return self.sz[self.get(x)]


n = int(input())
e = Graph(n + 1)
for _ in range(1, n):
    u, v = map(int, input().split())
    e.append(u, v)
    e.append(v, u)
fa = array('i', [0] * (n + 1))


@bootstrap
def dfs(u: int):
    f = fa[u]
    for v in e.iterate(u):
        if v != f:
            fa[v] = u
            yield dfs(v)
    yield


dfs(1)
pos = array('i', [0] * (n + 1))
L = 1


def solve() -> str:
    global L
    a = list(map(int, input().split()))[1:]
    m = len(a)
    R = L + m
    for i, x in enumerate(a, L):
        pos[x] = i
    dsu = DSU(m)
    for i, x in enumerate(a, L):
        y = fa[x]
        j = pos[y]
        if L <= j < R:
            dsu.merge(i - L, j - L)
    ans = 0
    for i in range(m):
        if dsu.get(i) == i:
            sz = dsu.size(i)
            ans += sz * (sz - 1) // 2
    L = R
    return str(ans)


print('\n'.join(solve() for _ in range(int(input()))))
