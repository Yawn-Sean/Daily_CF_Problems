from math import inf

s = input()
t = input()
n = int(input())

dis = [[inf] * 26 for _ in range(26)]
for i in range(26):
  dis[i][i] = 0

for _ in range(n):
  a, b, w = input().split()
  dis[ord(a) - ord('a')][ord(b) - ord('a')] = min(dis[ord(a) - ord('a')][ord(b) - ord('a')], int(w))

for k in range(26):
  for i in range(26):
    for j in range(26):
      dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j])

if len(s) != len(t):
  print(-1)
  exit()

res = 0
s_res = []
for x, y in zip(s, t):
  a, b = ord(x) - ord('a'), ord(y) - ord('a')
  t, c = inf, 'a'
  for i in range(26):
    if dis[a][i] + dis[b][i] < t:
      t = dis[a][i] + dis[b][i]
      c = chr(i + ord('a'))

  res += t
  s_res.append(c)

if res == inf:
  print(-1)
  exit()

print(res)
print(''.join(s_res))
