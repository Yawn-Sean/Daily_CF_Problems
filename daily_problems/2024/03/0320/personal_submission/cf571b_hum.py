import sys

input = lambda: sys.stdin.readline().rstrip()

n, k = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

m1 = n % k
v = n // k

inf = float('inf')
dp = [inf] * (m1 + 1)

dp[0] = 0

for i in range(1, k + 1):
  ndp = [inf] * (m1 + 1)
  for j in range(m1 + 1):
    if i - 1 - j >= 0:
      idx = j * (v + 1) + (i - 1 - j) * v
      ndp[j] = min(ndp[j], dp[j] + a[idx + v - 1] - a[idx])
    if j - 1 >= 0 and i - j >= 0:
      idx = (j - 1) * (v + 1) + (i - j) * v
      ndp[j] = min(ndp[j], dp[j - 1] + a[idx + v] - a[idx])
  dp = ndp
print(dp[m1])
