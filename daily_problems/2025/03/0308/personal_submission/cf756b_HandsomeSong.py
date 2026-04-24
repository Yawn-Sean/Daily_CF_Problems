import sys
input = sys.stdin.readline
def II():
    return int(input())
n=II()
t=[-10**18]
for _ in range(n):
    t.append(II())
p1=p2=0
dp=[0]*(n+1)
for i in range(1,n+1):
    dp[i]=dp[i-1]+20
    while t[i]-t[p1]>=90:
        p1+=1
    dp[i]=min(dp[i],dp[p1-1]+50)
    while t[i]-t[p2]>=1440:
        p2+=1
    dp[i]=min(dp[i],dp[p2-1]+120)
print('\n'.join(str(dp[i+1] - dp[i]) for i in range(n)))