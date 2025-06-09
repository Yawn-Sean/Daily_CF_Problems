def solve():
    n,m=MII()
    c1=0;x=n-1
    while x:
        c1+=1
        x//=7
    c1=max(c1,1)
    c2=0;x=m-1
    while x:
        c2+=1
        x//=7
    c2=max(c2,1)
    @lru_cache
    def dfs(i,mask,x,y):
        if i==c1+c2:
            return 1
        res=0
        if i<c1:
            for j in range(7):
                if (mask>>j)&1==0 and x+j*(7**i)<n:
                    res+=dfs(i+1,mask+(1<<j),x+j*(7**i),y)
        else:
            for j in range(7):
                if (mask>>j)&1==0 and y+j*(7**(i-c1))<m:
                    res+=dfs(i+1,mask+(1<<j),x,y+j*(7**(i-c1)))
        return res
    print(dfs(0,0,0,0))
    return
