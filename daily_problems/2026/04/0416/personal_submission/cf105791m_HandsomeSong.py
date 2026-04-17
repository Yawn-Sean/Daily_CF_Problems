def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
def LI():
    return list(input().split())
def I():
    return input().strip()
    
n=II()
c=[[]for _ in range(n)]
for i in range(n):
    c[i]=LII()
if n==1:
    print(0)
else:
    inf=10**18
    dp=[[inf]*(1<<n)for _ in range(n)]
    dp[0][1]=0
    for i in range(1<<n):
        for j in range(n):
            if dp[j][i]<inf:
                for nj in range(n):
                    if i>>nj&1:
                        continue
                    ni=i|(1<<nj)
                    dp[nj][ni]=min(dp[nj][ni],dp[j][i]+c[j][nj])
    print(min(dp[i][(1<<n)-1]+c[i][0]for i in range(n)))