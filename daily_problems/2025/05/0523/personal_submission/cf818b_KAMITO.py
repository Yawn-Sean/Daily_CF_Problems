def solve():
    n,m=MII()
    l=LMII()
    a=[0]*(n+1)
    vis=[0]*(n+1)
    for i in range(m-1):
        x=(l[i+1]-l[i])
        if x<=0:
            x+=n
        if a[l[i]]==0:
            if not vis[x]:
                vis[x]=True
            else:
                print(-1)
                return
            a[l[i]]=x
        elif a[l[i]]!=x:
            print(-1)
            return
    j=1
    for i in range(1,n+1):
        if a[i]==0:
            while j<=n and vis[j]:
                j+=1
            a[i]=j
            vis[j]=True
    print(*a[1:])
    return
