def solve():
    n=int(input())
    s=list(set(map(int,input().split())))
    s.sort()
    m=len(s)
    c=[0]
    for i in range(1,m):
        c.append(s[i]-s[i-1]-1)
    c.sort()
    sc=[0]*m
    for i in range(1,m):
        sc[i]=sc[i-1]+c[i]
    q=int(input())
    for i in range(q):
        L,R=map(int,input().split())
        d=R-L-1
        l,r=0,m-1
        while l<r:
            mid=l+r+1>>1
            if c[mid]<=d:
                l=mid
            else:
                r=mid-1
        ans=m+sc[l]+(m-1-l)*(d+1)+R-L
        print(ans,end=' ')
    return


test=1
# test=int(input())
for _ in range(test):
    solve()
