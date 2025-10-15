def solve():
    n=II()
    r=LMII()
    cnt=Counter(r)
    R=[]
    for i,j in cnt.items():
        R.append([-j,i])
    heapify(R)
    ans=[]
    while len(R)>=3:
        cx,x=heappop(R)
        cy,y=heappop(R)
        cz,z=heappop(R)
        ans.append([x,y,z])
        cx+=1;cy+=1;cz+=1
        if cx:
            heappush(R,[cx,x])
        if cy:
            heappush(R,[cy,y])
        if cz:
            heappush(R,[cz,z])
    print(len(ans))
    for i in ans:
        i=list(sorted(i,reverse=True))
        print(*i)
    return
