import sys
input = lambda: sys.stdin.readline().rstrip()
n, m, k = map(int, input().split())
a = [[0] * (m + 1) for _ in range(n)]
res = 0
for i in range(n):
  s = input()
  tmp = []
  for j in range(m):
    if s[j] == '1':
      tmp.append(j)
  if len(tmp):
    t = tmp[-1] - tmp[0] + 1
    res += t
    length = len(tmp)
    a[i][length] = t

    for l in range(length):
      for r in range(l, length):
        a[i][length - (r - l + 1)] = max(a[i][length - (r - l + 1)], t - (tmp[r] - tmp[l] + 1))

dp = [0] * (k + 1)
for i in range(n):
  for j in range(k, -1, -1):
    for pre in range(j + 1):
      if j - pre <= m:
        dp[j] = max(dp[j], dp[pre] + a[i][j - pre])

print(res - dp[k])
