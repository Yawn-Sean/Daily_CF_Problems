import sys
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())

n, k = RII()
a = [inf] + list(range(1, k + 1))
s = sum(a[1:])
if s > n:
    print('NO')
else:
    n -= s
    s = 0
    for i in range(1, k + 1):
        a[i] += s
        right = k - i + 1
        x = min(2*a[i - 1] - a[i], n // right)
        a[i] += x
        s += x # 后缀需要增加s
        n -= right * x
    if n:
        print('NO')
    else:
        print('YES')
        print(' '.join(map(str, a[1:])))