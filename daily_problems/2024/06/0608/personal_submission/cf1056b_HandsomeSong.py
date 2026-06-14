import sys
input = sys.stdin.readline
def MII():
    return map(int,input().split())
n,m=MII()
mod=n%m
div=n//m
cnt=[div]*m
for i in range(1,mod+1):
    cnt[i]+=1
ans=0
for i in range(m):
    for j in range(m):
        if (i**2+j**2)%m==0:
            ans+=cnt[i]*cnt[j]
print(ans)