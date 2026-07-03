import sys
input=sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int,input().split())
t=II()
for _ in range(t):
    n,m,k=MII()
    if m%2==1:
        ans=min(n,k)
    else:
        ans=min(n,k,n*m-k)
    if ans%2!=k%2:
        ans-=1
    print(ans)