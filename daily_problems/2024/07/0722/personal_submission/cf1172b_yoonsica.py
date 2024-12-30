import sys

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mod = 998244353
n = RI()
ans = 1
deg = [0] * (n + 1)
for _ in range(n - 1):
    a, b = RII()
    deg[a] += 1
    deg[b] += 1
    ans = ans * deg[a] * deg[b] % mod
print(n * ans % mod)
