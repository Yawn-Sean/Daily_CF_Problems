import sys
from collections import defaultdict, deque, Counter
from itertools import accumulate
from heapq import *
from bisect import *
from types import GeneratorType
from heapq import *
from typing import List
from math import inf

mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x
standard_input = True
if standard_input:
    RI = lambda: int(sys.stdin.readline().strip())
    RF = lambda: float(sys.stdin.readline().strip())
    RS = lambda: sys.stdin.readline().strip()
    RFF = lambda: map(float, sys.stdin.readline().strip().split())
    RII = lambda: map(int, sys.stdin.readline().strip().split())
    RILIST = lambda: list(RII())
    RFLIST = lambda: list(RFF())

else:
    RI = lambda: int(input())
    RF = lambda: float(input())
    RS = lambda: input()
    RFF = lambda: map(float, input())
    RII = lambda: map(int, input().split())
    RILIST = lambda: list(RII())
    RFLIST = lambda: list(RFF())
    fin = open('input.txt', 'r')
    fout = open('output.txt', 'w')
    input = lambda: fin.readline().strip()
    
    
    def print(x):
        fout.write(str(x))

# https://codeforces.com/contest/1842/submission/

n = RI()
g = []
for _ in range(n):
    g.append(RS())

d = [[0]*(2*n) for _ in range(2*n)] # 默认每个方向都可以
for i in range(1, 2*n):
    for j in range(1, 2*n):
        d[i][j] = 1

for i, row in enumerate(g, 1):
    for j, c in enumerate(row, 1):
        if c == 'o': # 棋子
            for x in range(1, n + 1):
                for y in range(1, n + 1):
                    if g[x - 1][y - 1] == '.': # 这个方向不行
                        d[x - i + n][y - j + n] = 0

t = [[0]*(n + 1) for _ in range(1 + n)] # 记录所有棋子的攻击范围
for i, row in enumerate(g, 1):
    for j, c in enumerate(row, 1):
        if c == 'o':
            # 判断每个能走的方向
            for x in range(1, 2*n):
                for y in range(1, 2*n):
                    if d[x][y]:
                        nx, ny = i + x - n, j + y - n
                        if 1 <= nx <= n and 1 <= ny <= n:
                            t[nx][ny] = 1
flag = True
for i, row in enumerate(g, 1):
    for j, c in enumerate(row, 1):
        if c != 'o':
            flag &= ((c == 'x') == (t[i][j] == 1))

if not flag:
    print('NO')
else:
    print('YES')
    d[n][n] = 2
    for i in range(1, 2*n):
        ans = []
        for j in range(1, 2 * n):
            ans.append('.xo'[d[i][j]])
        print(''.join(ans))