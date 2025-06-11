n, mod = map(int, input().split())
dp = [0] * (n + 1)
dp[1] = 1
s = 1
for i in range(2, n + 1):
  dp[i] = s

  l = 2
  while l <= i:
    r = i // (i // l)
    dp[i] = (dp[i] + (r - l + 1) * dp[i // l]) % mod
    l = r + 1

  s = (s + dp[i]) % mod

print(dp[n])
