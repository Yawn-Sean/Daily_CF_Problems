n, k = map(int, input().split())
a = list(map(int, input().split()))


def check(x):
  dp = [1] * n
  for i in range(n):
    for j in range(i):
      if abs(a[i] - a[j]) <= x * (i - j):
        dp[i] = max(dp[i], dp[j] + 1)

  return max(dp) + k >= n


l = 0
r = 2 * 10 ** 9
while l < r:
  mid = (l + r) // 2
  if check(mid):
    r = mid
  else:
    l = mid + 1

print(l)