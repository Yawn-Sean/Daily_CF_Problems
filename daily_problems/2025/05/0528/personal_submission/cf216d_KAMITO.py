def solve():
    n=II()
    p=[]
    k=[]
    for i in range(n):
        t=LMII()
        k.append(t[0])
        p.append(t[1:])
        p[i].sort()
    def find(L,R,i):
        l=0;r=k[i]-1
        while l<r:
            mid=l+r>>1
            if p[i][mid]>=L:
                r=mid
            else:
                l=mid+1
        if p[i][r]<L:
            return 0
        s=r
        l=0;r=k[i]-1
        while l<r:
            mid=l+r+1>>1
            if p[i][mid]<=R:
                l=mid
            else:
                r=mid-1
        if p[i][l]>R:
            return 0
        t=r
        return t-s+1
    ans=0
    for i in range(n):
        for j in range(k[i]-1):
            L,R=p[i][j],p[i][j+1]
            left=find(L,R,(i-1)%n)
            right=find(L,R,(i+1)%n)
            if left!=right:
                ans+=1
    print(ans)
    return
