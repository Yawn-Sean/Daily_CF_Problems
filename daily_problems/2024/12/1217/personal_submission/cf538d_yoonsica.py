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

d = [[1]*(2*n) for _ in range(2*n)] # 默认每个方向都可以
for i, row in enumerate(g, 1):
    for j, c in enumerate(row, 1):
        if c == 'o': # 棋子
            for x in range(n):
                for y in range(n):
                    if g[x][y] == '.': # 这个方向不行
                        d[x - i + n][y - j + n] = 0

t = [[0]*(2*n) for _ in range(2*n)] # 记录所有棋子的攻击范围
for i, row in enumerate(g, 1):
    for j, c in enumerate(row, 1):
        if c == 'o':
            # 判断每个能走的方向
            for x in range(1, 2*n):
                for y in range(1, 2*n):
                    nx, ny = i + x -
                    if d[x - i, y - j]:
                        t[x, y] = 1
flag = True
for i, row in enumerate(g):
    for j, c in enumerate(row):
        if c != 'o':
            flag &= (int(c == 'x') == t[i, j])

if not flag:
    print('NO')
else:
    print('YES')
    m = 2*n - 1
    ans = [['.']*m for _ in range(m)]
    # o在(n - 1, n - 1)
    for i in range(2*n - 1):
        for j in range(2*n - 1):
            if d[i - (n - 1), j - (n - 1)] == 1:
                ans[i][j] = 'x'
    ans[n - 1][n - 1] = 'o'
    print('\n'.join(''.join(row) for row in ans))