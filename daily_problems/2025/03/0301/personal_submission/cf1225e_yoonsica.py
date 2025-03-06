import sys
from collections import defaultdict
from itertools import pairwise
from math import comb

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x
mod = 10**9 + 7

'''
https://codeforces.com/problemset/problem/1225/E
'''
n, m = RII()
matrix = []
for _ in range(n):
    matrix.append(RS())

if matrix[0][0] == 'R' or matrix[-1][-1] == 'R':
    exit(print(0))
if n == m == 1:
    exit(print(1))
r = [[0]*(m + 1) for _ in range(n + 1)]
d = [[0]*(m + 1) for _ in range(n + 1)]
for i in range(n - 1, -1, -1):
    for j in range(m - 1, -1, -1):
        if matrix[i][j] == 'R':
            r[i][j] = d[i][j] = 1
        r[i][j] += r[i][j + 1]
        d[i][j] += d[i + 1][j]

f = [[0] * (m + 2) for _ in range(n + 2)] # 下
g = [[0] * (m + 2) for _ in range(n + 2)] # 右

f[1][1] = g[1][1] = 1
f[2][1] = g[1][2] = -1 # 避免重复计算贡献

for i in range(1, n + 1):
    for j in range(1, m + 1):
        f[i][j] = (f[i][j] + f[i - 1][j] + g[i - 1][j]) % mod # 最后一步是从上边下来
        g[i][m - r[i - 1][j] + 1] = (g[i][m - r[i - 1][j] + 1] - f[i][j]) % mod # 下来后向右走，没箱子能走到m，现在(i, j）右侧有r[i][j + 1]个箱子,不考虑(i,j)本身的箱子，因为此时认为可以向下推
        g[i][j] = (g[i][j] + f[i][j - 1] + g[i][j - 1]) % mod # 最后一步是从左边过来
        f[n - d[i][j - 1] + 1][j] = (f[n - d[i][j - 1] + 1][j] - g[i][j]) % mod

print((f[n][m] + g[n][m]) % mod)