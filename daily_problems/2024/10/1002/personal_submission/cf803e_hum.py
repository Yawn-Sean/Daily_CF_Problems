n, k = map(int, input().split())
s = input()
base = k

dp = [[-2] * (2 * k + 1) for _ in range(n + 1)]

dp[0][0 + base] = 0

d = {'L': [-1], 'D': [0], 'W': [1], '?': [-1, 0, 1]}

for i in range(n):
  for dj in d[s[i]]:
    for j in range(-k + 1, k):
      if dp[i][j + base] != -2:
        dp[i + 1][j + dj + base] = dj

if dp[n][-k + base] != -2:
  cur = -k
elif dp[n][k + base] != -2:
  cur = k
else:
  print("NO")
  exit()

status = {
  -1: 'L',
  0: 'D',
  1: 'W'
}

res = []

for i in range(n, 0, -1):
  res.append(status[dp[i][cur + base]])
  cur -= dp[i][cur + base]

print("".join(res[::-1]))
