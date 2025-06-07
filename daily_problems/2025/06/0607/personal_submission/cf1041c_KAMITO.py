def solve():
    n,m,d=MIIS()
    a=LMIIS()
    a=list(enumerate(a))
    a.sort(key=lambda x:x[1])
    ans=[0]*n
    idx=1
    q=[]
    for i in range(n):
        if q and q[0][0]+d<a[i][1]:
            x,y=heappop(q)
            heappush(q,[a[i][1],y])
            ans[a[i][0]]=y
        else:
            ans[a[i][0]]=idx
            heappush(q,[a[i][1],idx])
            idx+=1
    print(max(ans))
    print(*ans)
    return
