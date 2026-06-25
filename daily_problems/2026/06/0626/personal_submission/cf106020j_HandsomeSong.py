import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
t=II()
for _ in range(t):
    n,k=MII()
    if n==2:
        if k&-k==k:
            print(1)
        else:
            print(0)
    else:
        v=k-n
        if n%2==0 and v==n//2+1:
            print(1)
        else:
            print(max(0,n-1-2*v))