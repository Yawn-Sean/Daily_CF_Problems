"""
在一条链的基础上继续添加边即可。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

P = 100003  # 是个质数

n, m = lii()
print(P, P)
for u in range(1, n-1):
    print(u, u+1, 1)
print(n-1, n, P-(n-2))
m -= n-1
for u in range(1, n+1):
    if m == 0: break
    for v in range(u+2, n+1):
        if m == 0: break
        print(u, v, P)
        m -= 1
