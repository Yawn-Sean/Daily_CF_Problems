import sys
input=sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int,input().split())
def factorize(n):
    exps=[]
    while n>1:
        p=spf[n]
        cnt=0
        while n%p==0:
            cnt+=1
            n//=p
        exps.append(cnt)
    return exps
mx=200001
spf=list(range(mx))
for i in range(2,mx):
    if spf[i]==i:
        for j in range(i*i,mx,i):
            if spf[j]==j:
                spf[j]=i
tc=II()
out=[]
for _ in range(tc):
    x,k=MII()
    exps=factorize(x)
    lo,hi=0,61
    while lo<hi:
        mid=(lo+hi+1)//2
        mod=1<<mid
        cost=sum((mod-e % mod) % mod for e in exps)
        if cost <=k:
            lo=mid
        else:
            hi=mid-1
    print(lo)