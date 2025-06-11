n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))
dp = [2] * n
mod = 10 ** 9 + 7
for i in range(n):
  for j in range(a[i], i):
    dp[i] += dp[j]
    dp[i] %= mod

print(sum(dp) % mod)
