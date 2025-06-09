def solve():
    n,x=MII()
    a=LMII()
    b=LMII()
    a.sort()
    b.sort()
    ans=0
    j=0
    for i in range(n-1,-1,-1):
        while j<n and a[i]+b[j]<x:
            j+=1
        if j<n:
            ans+=1
            j+=1
    print(1,ans)
    return
