import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
t=II()
for _ in range(t):
    n=II()
    a=LII()
    count=[0]*(n+2)
    for x in a:
        if x<=n:
            count[x]+=1
    mex=0
    while count[mex]>0:
        mex+=1
    dp=[0]*(mex+1)
    for i in range(mex-1,-1,-1):
        dp[i]=10**18
        ci=count[i]
        for j in range(i+1,mex+1):
            cost=dp[j]+(ci-1)*j+1
            if cost<dp[i]:
                dp[i]=cost
    print(dp[0]-1 if dp[0]!=0 else dp[0])
