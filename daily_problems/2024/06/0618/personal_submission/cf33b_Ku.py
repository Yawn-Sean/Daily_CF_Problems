#https://codeforces.com/problemset/problem/33/B
import sys
from math import *
iput = lambda:sys.stdin.readline().rstrip()
RI = lambda:int(sys.stdin.readline().rstrip())
RII = lambda:map(int,sys.stdin.readline().rstrip().split())
RIII = lambda : sys.stdin.readline().rstrip().split()
RLIST = lambda:list(map(int,sys.stdin.readline().rstrip().split()))
s1 = list(input())
s2 = list(input())
n = RI()
li = [[inf] * 26 for _ in range(26)]
for i in range(26):
    li[i][i] = 0
for _ in range(n):
    e,f,w = RIII()
    a = ord(e) - ord('a')
    b = ord(f) - ord('a')
    li[a][b] = min(li[a][b],int(w))
for k in range(26):
    for i in range(26):
        for j in range(26):
            if li[i][k] + li[k][j] < li[i][j]:
                li[i][j] = li[i][k] + li[k][j]
ans = 0
cnt = []
if len(s1) != len(s2):
    print(-1)
    exit()
m = len(s1)
for i in range(m):
    res = inf
    opt = -1
    e,f = s1[i],s2[i]
    x = ord(e) - ord('a')
    y = ord(f) - ord('a')
    for j in range(26):
        if li[x][j] < inf and li[y][j] < inf:
            if li[x][j] + li[y][j] < res:
                res = li[x][j] + li[y][j]
                opt = j
    if opt == -1:
        print(-1)
        exit()
    else:
        ans += res
        cnt.append(chr(opt + 97))

print(ans)
print(''.join(cnt))
