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
    n,x=MII()
    a=LII()
    s=0
    mn=min(a)
    mx=max(a)
    for i in range(n):
        if i>0:
            s+=abs(a[i]-a[i-1])
    low=0
    if mx>1:
        low=min(a[0]-1,a[-1]-1,2*mn-2)
    high=0
    if mx<x:
        high=min(x-a[0],x-a[-1],2*x-2*mx)
    print(s+low+high)