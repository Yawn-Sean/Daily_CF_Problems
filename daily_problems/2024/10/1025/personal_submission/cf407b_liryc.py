'''
https://codeforces.com/problemset/submission/407/287874832
407B
2024/10/25 Y1
1600
DP
'''
# ref 
n = int(input())
a = list(map(int, input().split()))
for i in range(n):
    a[i] -= 1
MOD = 1000000007

dp = [0] * (n + 1)

for i in range(n):
    dp[i + 1] = (dp[i] * 2 - dp[a[i]] + 2) % MOD

print(dp[n])