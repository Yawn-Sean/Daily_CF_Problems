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
A = LI()
B = LI()

cur = 0
for a in A:
    cur ^= a
for b in B:
    cur ^= b
if cur != 0:
    exit(print('NO'))
else:
    print('YES')

mtx = [[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
    mtx[i][0] = A[i]
for j in range(1, m):
    mtx[0][j] = B[j]
    mtx[0][0] ^= B[j]


for i in range(n):
    print(*mtx[i])
