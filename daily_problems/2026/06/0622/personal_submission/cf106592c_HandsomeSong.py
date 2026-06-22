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
    a=LII()
    l=0
    h=10**18
    while l<h:
        m=(l+h+1)//2
        s=0
        for x in a:
            s+=min(x,m)
            if s>n:
                break
        if s<=n:
            l=m
        else:
            h=m-1
    base=l
    b=[min(a[i],base) for i in range(k)]
    rem=n-sum(b)
    for i in range(k):
        if rem>0 and a[i]>base:
            b[i]+=1
            rem-=1
        if rem==0:
            break
    print(*b)
    
    