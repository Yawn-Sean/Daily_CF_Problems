def solve():
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    N=5000
    cnt1=[0]*N
    for i in range(n):
        for j in range(i+1,n):
            cnt1[a[j]-a[i]]+=1
    cnt2=[0]*N
    for i in range(N):
        for j in range(N):
            if i+j<N:
                cnt2[i+j]+=cnt1[i]*cnt1[j]
    for i in range(N-2,0,-1):
        cnt1[i]+=cnt1[i+1]
    ans=0
    for i in range(2,N-1):
        ans+=cnt1[i+1]*cnt2[i]
    m=n*(n-1)//2
    print(ans/(m*m*m))

    return


test=1
# test=int(input())
for _ in range(test):
    solve()
