#计算每个数到最近平方数和非平方数的次数，然后反悔贪心
def solve():
    n=II()
    a=LIIS()
    cnt=[]
    def issquare(x):
        y=isqrt(x)
        return y*y==x
    for i in range(n):
        if issquare(a[i]):
            x=0
            y=inf
            c=0
            z=a[i]
            while issquare(z):
                c+=1
                z+=1
            y=c
            c=0
            z=a[i]
            while issquare(z) and z>0:
                c+=1
                z-=1
            if not issquare(z):
                y=min(y,c)
        else:
            y=0
            z=isqrt(a[i])
            x=min(a[i]-z*z,(z+1)*(z+1)-a[i])
        cnt.append([x,y])
    ans=0
    c=0
    q=[]
    for i in range(n):
        x1,y1=cnt[i]
        if c<n//2:
            ans+=x1
            c+=1
            heappush(q,[y1-x1,x1,y1])
        elif q:
            d,x2,y2=q[0]
            if x1+y2<x2+y1:
                ans+=y2-x2+x1
                heappop(q)
                heappush(q,[y1-x1,x1,y1])
            else:
                ans+=y1
        else:
            ans+=y1
    print(ans)
    return
