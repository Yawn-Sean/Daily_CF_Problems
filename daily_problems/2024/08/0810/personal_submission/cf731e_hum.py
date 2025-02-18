from itertools import accumulate

n = int(input())
a = list(map(int, input().split()))
acc = list(accumulate(a))
dp = [0] * n
m = acc[n - 1]
for i in range(n - 2, -1, -1):
  dp[i] = m
  m = max(m, acc[i] - dp[i])

print(dp[0])
