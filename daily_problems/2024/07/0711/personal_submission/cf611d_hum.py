n = int(input())
s = input()
m = n + 1
dp = [0] * (m * m)
acc = [0] * (m * m)


def f(a, b):
  return a * m + b


dp[f(0, 0)] = 1
acc[f(0, 0)] = 1

for l in range(1, n + 1):
  acc[f(0, l)] += acc[f(0, l - 1)]

mod = 10 ** 9 + 7

lcp = [[0] * n for _ in range(n)]
for i in range(n - 1, -1, -1):
  for j in range(i + 1, n):
    if s[i] == s[j]:
      lcp[i][j] = 1
      if j + 1 < n:
        lcp[i][j] += lcp[i + 1][j + 1]


def check(i, j, k):
  l = lcp[i][j]
  return l < k and s[i + l] < s[j + l]


for i in range(1, n + 1):
  for l in range(1, i + 1):
    if s[i - l] == '0':
      continue
    dp[f(i, l)] = acc[f(i - l, l - 1)]
    if i - l * 2 >= 0 and s[i - l * 2] != '0' and check(i - l * 2, i - l, l):
      dp[f(i, l)] += dp[f(i - l, l)]
      if dp[f(i, l)] >= mod:
        dp[f(i, l)] -= mod

  for l in range(1, n + 1):
    acc[f(i, l)] = acc[f(i, l - 1)] + dp[f(i, l)]
    if acc[f(i, l)] >= mod:
      acc[f(i, l)] -= mod

print(acc[f(n, n)])
