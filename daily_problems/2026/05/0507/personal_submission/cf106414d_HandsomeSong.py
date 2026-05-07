import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
t=II()
for _ in range(t):
    n,k=MII()
    c=LII()
    c[k-1],c[-1]=c[-1],c[k-1]
    vis=[0]*(n+1)
    for i in range(n-1):
        vis[c[i]]=1
    mex=0
    while vis[mex]:
        mex+=1
    if c[-1]>=mex:
        print(-1,-1)
    else:
        print(k,n)