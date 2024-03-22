import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
a = list(map(int, input().split()))
m = max(a)
dp = [0] * (m + 1)
for i in a:
  dp[i] += 1
  for j in range(i, m + 1, i):
    dp[j] = max(dp[j], dp[i])

print(max(dp))
