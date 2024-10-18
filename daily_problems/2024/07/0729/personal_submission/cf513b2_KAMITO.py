def solve():
    n,m=map(int,input().split())
    ans=[0]*n
    l=0;r=n-1;s=0
    for i in range(1,n+1):
        x=2**(n-i-1)
        if s+x<m:
            s+=x
            ans[r]=i
            r-=1
        else:
            ans[l]=i
            l+=1
    print(*ans)



    return


test=1
# test=int(input())
for _ in range(test):
    solve()
