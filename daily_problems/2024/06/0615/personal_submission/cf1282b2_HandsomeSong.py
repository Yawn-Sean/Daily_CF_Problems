import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
def LI():
    return list(input().strip())
def I():
    return input().strip()
t=II()
for _ in range(t):
    n,p,k=MII()
    a=[0]+LII()
    a.sort()
    for i in range(1,n+1):
        if i<k:
            a[i]+=a[i-1]
        else:
            a[i]+=a[i-k]
    ans=n
    for i in range(n,-1,-1):
        if a[i]<=p:
            ans=i
            break
    print(ans)