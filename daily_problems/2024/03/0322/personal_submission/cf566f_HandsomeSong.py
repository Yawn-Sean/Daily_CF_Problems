def II():
    return int(input())
def LII():
    return list(map(int, input().split()))

n=II()
a=LII()

cnt=[0]*(10**6+1)
for num in a:
    cnt[num]+=1
dp=[0]*(10**6+1)
for i in range(1,10**6+1):
    dp[i]+=cnt[i]
    for j in range(i,10**6+1,i):
        dp[j]=max(dp[j],dp[i])
print(max(dp))