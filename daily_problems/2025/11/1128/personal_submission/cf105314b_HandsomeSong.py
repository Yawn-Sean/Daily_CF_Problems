from itertools import accumulate
def II():
    return int(input())
def MII():
    return map(int, input().split())
def LII():
    return list(map(int, input().split()))
t=II()
for _ in range(t):
    n,m=MII()
    a=sorted(LII())
    l=1
    r=10**7
    while l<=r:
        p=0
        cnt=0
        mid=(l+r)//2
        for i in range(n):
            while p<n and a[p]-a[i]<mid:
                p+=1
            cnt+=2*(n-p)

        if cnt>m:
            l=mid+1
        else:
            r=mid-1
    acc=list(accumulate(a,initial=0))

    p=0
    sm=0
    cnt=0
    for i in range(n):
        while p<n and a[p]-a[i]<l:
            p+=1
        cnt+=2*(n-p)
        sm+=2*(acc[n]-acc[p]-a[i]*(n-p))
    sm+=(m-cnt)*(l-1)
    print(sm)