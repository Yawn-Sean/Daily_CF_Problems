def solve():
    n,m=MII()
    a=[]
    for i in range(n):
        a.append(LMII())
    change=False
    if n>m:
        change=True
        a=[list(i) for i in zip(*a)]
        n,m=m,n
    ans=[]
    for i in range(n):
        x=min(a[i])
        if x==0:
            continue
        for j in range(m):
            a[i][j]-=x
        for j in range(x):
            ans.append(['col' if change else 'row',i+1])
    for j in range(m):
        x=min([a[i][j] for i in range(n)])
        if x==0:
            continue
        for i in range(n):
            a[i][j]-=x
        for i in range(x):
            ans.append(['row' if change else 'col',j+1])
    for i in range(n):
        if max(a[i])!=0:
            print(-1)
            return
    print(len(ans))
    for i,j in ans:
        print(i,j)
    return
