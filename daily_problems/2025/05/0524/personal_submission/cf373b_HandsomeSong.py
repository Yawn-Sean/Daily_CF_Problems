import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
w,m,k=MII()
ans=0
while True:
    d=len(str(m))
    cost1=d*k
    if cost1>w:
        break
    upper=10**d
    mx=upper-m
    afford=w//cost1
    take=min(mx,afford)
    ans+=take
    w-=take*cost1
    m=upper
    if take<mx:
        break
print(ans)