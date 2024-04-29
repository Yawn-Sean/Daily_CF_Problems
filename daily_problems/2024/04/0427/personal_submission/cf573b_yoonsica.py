# 快读板子
import sys

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())

n = RI()
h = RILIST()

ans = 0
v = [n] * (n + 2)
v[0] = v[-1] = 0
for i, x in enumerate(h, 1):
    v[i] = min(v[i - 1] + 1, x)

for i in range(n, 0, -1):
    v[i] = min(v[i], v[i + 1] + 1)
    ans = max(ans, v[i])
print(ans)

