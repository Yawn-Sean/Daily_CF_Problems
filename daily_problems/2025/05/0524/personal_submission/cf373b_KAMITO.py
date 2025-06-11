def solve():
    w,m,k=MII()
    def calc(x):
        l=0
        y=x
        while y:
            l+=1
            y//=10
        res=0;j=9
        for i in range(1,l):
            res+=j*i
            j*=10
        res+=(x-int(10**(l-1))+1)*l
        return res
    def check(L):
        x=calc(m+L-1)-calc(m-1)
        return x*k<=w
    l=0;r=int(1e18)
    while l<r:
        mid=l+r+1>>1
        if check(mid):
            l=mid
        else:
            r=mid-1
    print(l)
    return
