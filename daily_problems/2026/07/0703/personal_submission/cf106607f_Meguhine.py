import sys
from array import array
from dataclasses import dataclass
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()


@dataclass(slots=True)
class Fac:  # init from [0, N), N is not stored, be careful to use
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


M = 64
MOD = 998244353
fac = Fac(M, MOD)
comb = [[0] * M for _ in range(M)]
for x in range(M):
    for y in range(x + 1):
        comb[x][y] = fac.C(x, y)


def solve() -> str:
    n, m = map(int, input().split())
    n %= MOD
    ans, c = 0, 0
    pw = array('i', accumulate(
        range(1, M),
        lambda pre, _: pre * n % MOD,
        initial=1
    ))
    for p in range(60, -1, -1):
        if m >> p & 1:
            for i in range(p + 1):
                ans += pw[c + i] * comb[p][i] % MOD
            ans %= MOD
            c += 1
    ans += pow(n, c, MOD)
    return str(ans % MOD)


print('\n'.join(solve() for _ in range(int(input()))))
