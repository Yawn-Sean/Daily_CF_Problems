n, m, b = map(int, input().split())
a = []
for i in range(n):
  x, k, _ = map(int, input().split())
  tmp = list(map(lambda x: int(x) - 1, input().split()))
  c = 0
  for y in tmp:
    c |= 1 << y
  a.append((k, x, c))

a.sort()

inf = 3 * 10 ** 18

dp = [inf] * (1 << m)
dp[0] = 0

res = inf
for k, x, c in a:
  for i in range((1 << m) - 1, -1, -1):
    if dp[i] + x < dp[i | c]:
      dp[i | c] = dp[i] + x

  if dp[-1] + k * b < res:
    res = dp[-1] + k * b

print(res) if res < inf else print(-1)
