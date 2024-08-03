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

edges = [LGMI() for _ in range(m)]

mtx = [[0 for _ in range(n)] for _ in range(n)]
for i in range(m):
    u, v = edges[i]
    mtx[u][v] = 1
    mtx[v][u] = 1

color = [0] * n
q = []
for i in range(n):
    for j in range(i, n):
        if i == j:
            continue
        if mtx[i][j] == 0:
            color[i] = 1
            q.append(i)
            break
    if q:
        break

while q:
    i = q.pop()
    for j in range(n):
        if i == j:
            continue
        if mtx[i][j] == 0 and color[j] == 0:
            color[j] = - color[i]
            q.append(j)

mtx2 = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        if abs(color[i] - color[j]) <= 1:
            mtx2[i][j] = 1

for i in range(n):
    for j in range(n):
        if mtx[i][j] != mtx2[i][j]:
            print('No')
            exit()

print('Yes')
print(''.join(chr(98 + x) for x in color))
