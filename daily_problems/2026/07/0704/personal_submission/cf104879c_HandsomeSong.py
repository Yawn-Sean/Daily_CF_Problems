import sys
import random
from collections import Counter
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,m=MII()
grid=[LII() for _ in range(n)]
rnd=random.getrandbits(30)
cnt=[[0]*m for _ in range(n)]
for i in range(n):
    d=Counter()
    for j in range(m-1,-1,-1):
        cnt[i][j]=d[grid[i][j]+j+rnd]
        d[grid[i][j]+j+rnd]+=1
ans=0
for j in range(m):
    d=Counter()
    for i in range(n-1,-1,-1):
        ans+=cnt[i][j]*d[grid[i][j]+i+rnd]
        d[grid[i][j]+i+rnd]+=1
print(ans)
