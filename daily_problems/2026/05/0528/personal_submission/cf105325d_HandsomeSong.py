import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
t=II()
for _ in range(t):
    n=II()
    a=LII()
    p=n-1
    ans=0
    for i in range(1,n+1):
        while p>=0 and a[p]<i:
            p-=1
        bi=p+1
        if a[i-1]>bi:
            ans+=a[i-1]-bi
    print(ans)