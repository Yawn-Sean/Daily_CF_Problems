import sys
from array import array
from dataclasses import dataclass
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()


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


@dataclass(slots=True)
class Fac:  # init from [1, N), N is not stored, be careful to use
    MOD: int
    fc: array
    fc_inv: array

    def __init__(self, N: int, MOD: int) -> None:
        self.MOD = MOD
        self.fc = array('i', accumulate(
            range(1, N),
            lambda pre, x: pre * x % MOD,
            initial=1
        ))
        self.fc_inv = array('i', [1] * N)
        self.fc_inv[-1] = pow(self.fc[-1], -1, MOD)
        for i in range(N - 2, 1, -1):
            self.fc_inv[i] = self.fc_inv[i + 1] * (i + 1) % MOD

    def C(self, x: int, y: int) -> int:
        if x == y:
            return 1
        if x < 0 or y < 0 or x - y < 0:
            return 0
        return self.fc[x] * self.fc_inv[y] * self.fc_inv[x - y] % self.MOD

    def inv(self, x: int) -> int:
        return self.fc[x - 1] * self.fc_inv[x] % self.MOD


MOD = 10**9 + 7
n, m = map(int, input().split())
dsu = DSU(n + 1)
ans = 0
for _ in range(m):
    u, v = map(int, input().split())
    if not dsu.merge(u, v):
        ans += 1
n -= m
print(f"{n=} {ans=}", file=sys.stderr)
fac = Fac(n + 1, MOD)
for x in range(1, n + 1):
    ans += fac.inv(x)
print(ans % MOD)


"""
题目允许自环的存在
那么建初始图后, 删掉已有的环, 剩下的链 (或者点) 都可以被看作是 **点**
假设剩余了 n 个点, 令 f(n) 表示 n 个点按照题意形成的图的期望环的个数,
那么求 f(n) 即可
- 如果是连接自身, 概率为 1/n, 多了一个环, 下次考虑 f(n-1)
- 如果是连接两个不同点, 概率为 1-(1/n), 下次依然考虑 f(n-1)
所以 f(n) := 1/n + f(n-1), 就是调和级数求和 !!!
"""
