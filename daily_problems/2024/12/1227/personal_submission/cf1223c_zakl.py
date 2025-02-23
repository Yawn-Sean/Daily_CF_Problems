def solve():
    n=_n()  
    ps=_nA()
    x,a=_nA()
    y,b=_nA()
    k=_n()
    ps.sort(reverse=True)
    def check(mid):
        tt=[]
        for i in range(1,mid+2):
            if i%a==0 and i%b==0:
                tt.append(x+y)
            elif i%a==0:
                tt.append(x)
            elif i%b==0:
                tt.append(y)
            else:
                tt.append(0)
        return sum(0.01*v*ps[i] for i,v in enumerate(sorted(tt,reverse=True)))>=k
    l,r=0,n-1
    while l<r:
        mid=(l+r)//2
        if check(mid):
            r=mid
        else:
            l=mid+1
    if check(l): print(l+1)
    else: print(-1)

solve()
