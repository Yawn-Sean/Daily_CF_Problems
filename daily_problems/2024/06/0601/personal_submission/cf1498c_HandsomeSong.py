import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
t=II()
mod = 10**9 + 7
for _ in range(t):
    n,k=MII()
    dp = [[0] * (n + 1) for _ in range(k + 1)]
    for j in range(n + 1):
        dp[1][j] = 1
    for i in range(2, k + 1):
        dp[i][0] = 1
        for j in range(1, n + 1):
            dp[i][j] = (dp[i][j-1] + dp[i-1][n-j]) % mod
    print(dp[k][n])