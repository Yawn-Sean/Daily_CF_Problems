from collections import Counter

s = input()
c = Counter(s)
a, b = c.most_common()[0]
if b >= 100:
  print(a * 100)
  exit()

n = len(s)
dp = [[0] * (n) for _ in range(n)]
for i in range(n - 1, -1, -1):
  dp[i][i] = 1
  for j in range(i + 1, n):
    if s[i] == s[j]:
      dp[i][j] = dp[i + 1][j - 1] + 2
    else:
      dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])

tmp = []
l, r = 0, n - 1
while l < r:
  if s[l] == s[r]:
    tmp.append(s[l])
    l += 1
    r -= 1
  elif dp[l + 1][r] > dp[l][r - 1]:
    l += 1
  else:
    r -= 1
res = ''.join(tmp)
if len(res) >= 50:
  res = res[:50]
  print(res + res[::-1])

else:
  if l == r:
    print(res + s[l] + res[::-1])
  else:
    print(res + res[::-1])
