s = input()
n = len(s)

f = [[0] * n for _ in range(n)]

for i in range(n):
  for j in range(n):
    if i >= j:
      f[i][j] = 1

for i in range(n - 1, -1, -1):
  for j in range(i + 1, n):
    if s[i] == s[j] and f[i + 1][j - 1]:
      f[i][j] = 1

cnt = [0] * n
cnt[0] += n
for i in range(n):
  for j in range(i + 1, n):
    cur = j
    t = 1
    while cur > i and f[i][cur]:
      cnt[t - 1] += 1
      cur = (i + cur + 1) // 2 - 1
      t += 1
      if cur == i:
        cnt[t - 1] += 1

print(*cnt)
