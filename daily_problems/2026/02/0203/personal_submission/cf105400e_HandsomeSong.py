t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    mn=min(a)
    mx=max(a)
    if mn==mx:
        print(10**n)
    else:
        ans=1
        for x in a:
            if x==mn:
                ans*=mn
            elif x==mx:
                ans*=(10-mx+1)
        print(ans)