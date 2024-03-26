# -*- coding: utf-8 -*-
import sys
from heapq import heappop, heappush

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

n = I()
ops = []
for _ in range(2*n):
    ss = input().split(' ')
    if len(ss) == 1:
        ops.append(ss)
    else:
        s, x = ss
        x = int(x)
        ops.append([s, x])

st = []
val = [0] * (2 * n)
for i in range(2*n):
    if ops[i][0] == '+':
        st.append(i)
    else:
        if len(st) == 0:
            exit(print('NO'))
        val[st.pop()] = ops[i][1]

h = []
res = []
for i in range(2 * n):
    if ops[i][0] == '+':
        res.append(val[i])
        heappush(h, val[i])
    else:
        if len(h) == 0 or h[0] != ops[i][1]:
            exit(print('NO'))
        else:
            heappop(h)
print('YES')
print(*res)
