n=int(input())
if n==1:
    print(1)
else :
    arr=list(map(int,input().split()))
    arr=[0,0]+arr
    dp=[0]*(n+1)
    for i in range(n,1,-1):
        if dp[i]==0:
            dp[i]=1
        dp[arr[i]]+=dp[i]
    dp=dp[1:]
    print(*sorted(dp))
