# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n, m = MI()

edges = []
for i in range(1, n - 1):
    edges.append((i, i + 1, 1))

edges.append((n - 1, n, 100003 - n + 2))
m -= n - 1
for k in range(2, n):
    if m == 0:
        break
    for i in range(1, n - k + 1):
        if m == 0:
            break
        edges.append((i, i + k, 100004))
        m -= 1
print(100003, 100003)
for edge in edges:
    print(*edge)
