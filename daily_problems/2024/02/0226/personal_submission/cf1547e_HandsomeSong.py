def II():
    return int(input())
def MII():
    return map(int, input().split())
def LII():
    return list(map(int, input().split()))
    
inf=10**18

q=II()
for _ in range(q):
    ff=input()
    n,k=MII()
    a=LII()
    t=LII()
    r=[inf]*n
    l=[inf]*n
    for j in range(k):
        p=a[j]-1
        tt=t[j]-1
        r[p]=tt-p
        l[p]=tt+p

    for i in range(1,n):
        r[i]=min(r[i],r[i-1])
    for i in range(n-1,0,-1):
        l[i-1]=min(l[i],l[i-1]) 

    print(*(min(r[i]+i+1,l[i]-i+1)for i in range(n)))
