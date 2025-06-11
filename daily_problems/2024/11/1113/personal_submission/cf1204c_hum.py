n = int(input())
grid = [input() for _ in range(n)]

dis = [[n + 1] * n for _ in range(n)]

for i in range(n):
  dis[i][i] = 0

for i in range(n):
  for j in range(n):
    if grid[i][j] == '1':
      dis[i][j] = 1

for i in range(n):
  for j in range(n):
    for k in range(n):
      dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k])

m = int(input())
route = list(map(lambda x: int(x) - 1, input().split()))

ans = [route[0]]
pt = 0

while pt < m - 1:
  npt = pt
  while npt < m - 1 and dis[route[pt]][route[npt + 1]] == dis[route[pt]][route[npt]] + 1:
    npt += 1
  ans.append(route[npt])
  pt = npt

print(len(ans))
print(' '.join(str(x + 1) for x in ans))
