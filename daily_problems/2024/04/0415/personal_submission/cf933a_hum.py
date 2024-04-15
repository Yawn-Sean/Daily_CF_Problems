n = int(input())
a = list(map(int, input().split()))

dp = [0] * 4
for v in a:
  if v == 1:
    dp[0] += 1
    dp[2] = max(dp[1] + 1, dp[2] + 1)
  else:
    dp[1] = max(dp[0] + 1, dp[1] + 1)
    dp[3] = max(dp[2] + 1, dp[3] + 1)

print(max(dp))
