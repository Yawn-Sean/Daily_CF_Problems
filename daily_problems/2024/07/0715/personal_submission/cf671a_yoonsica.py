import sys
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
# ---------------------------------------分割线---------------------------------------------------------


def dis(x, y, x1, y1):
    return ((x - x1) * (x - x1) + (y - y1) * (y - y1)) ** 0.5


ax, ay, bx, by, tx, ty = RII()
n = RI()
ans = 0
f1 = f2 = f3 = -inf # 仅使用一次a\b，使用两次
for _ in range(n):
    x, y = RII()
    dis1 = dis(x, y, ax, ay)
    dist = dis(x, y, tx, ty)
    dis2 = dis(x, y, bx, by)
    ans += 2 * dist
    f3 = max(f3, f1 + dist - dis2, f2 + dist - dis1)
    f1 = max(f1, dist - dis1)
    f2 = max(f2, dist - dis2)
    
print(ans - max(f1, f2, f3))
