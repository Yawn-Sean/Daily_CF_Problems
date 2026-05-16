import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
p=LII()
dp=[0]*(n+1)
for x in p:
    dp[x]=dp[x-1]+1
print(n-max(dp))