#https://codeforces.com/problemset/problem/1033/C
import sys
from math import *
iput = lambda:sys.stdin.readline().rstrip()
RI = lambda:int(sys.stdin.readline().rstrip())
RII = lambda:map(int,sys.stdin.readline().rstrip().split())
RIII = lambda : sys.stdin.readline().rstrip().split()
RLIST = lambda:list(map(int,sys.stdin.readline().rstrip().split()))
n = RI()
li = RLIST()
for i,x in enumerate(li):
    li[i] = x - 1
pos = [0] * n
for i in range(n):
    pos[li[i]] = i
ans = [False] * n
for i in range(n-1,-1,-1):
    x = i + 1
    for j in range((pos[i] % x), n, x):
        if li[j] > i and (not ans[j]):
            ans[pos[i]] = True
            break
res = []
for x in ans:
    if x:
        res.append('A')
    else:
        res.append('B')
print(''.join(res))
