import sys
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,m,k=MII()
grid=[LII()for _ in range(n)]
ans=0
cnt=0
pref=[0]*(n+1)
for i in range(m):
    for j in range(n):
        pref[j+1]=pref[j]+grid[j][i]
    res=0
    idx=0
    for j in range(n):
        if grid[j][i]:
            v=pref[min(j+k,n)]-pref[j]
            if v>res:
                res=v
                idx=pref[j]
    ans+=res
    cnt+=idx
print(ans,cnt)