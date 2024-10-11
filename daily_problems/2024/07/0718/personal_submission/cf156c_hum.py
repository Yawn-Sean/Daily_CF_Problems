import sys

input = lambda: sys.stdin.readline().rstrip()

t = int(input())
mod = 10 ** 9 + 7
m = 100
acc = m * 25
dp = [[0] * (acc + 1) for _ in range(m)]
for i in range(26):
  dp[0][i] = 1
for i in range(1, m):
  for j in range(acc + 1):
    for k in range(26):
      if j - k >= 0:
        dp[i][j] += dp[i - 1][j - k]
        if dp[i][j] >= mod:
          dp[i][j] -= mod

for _ in range(t):
  s = input()
  n = len(s)
  s = sum([ord(c) - ord('a') for c in s])
  print((dp[n - 1][s] - 1) % mod)
