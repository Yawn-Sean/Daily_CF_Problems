n = int(input())
ps = []
for _ in range(n):
  x, y = map(int, input().split())
  ps.append((x, y))

res = float('inf')
for i in range(-1, n - 1):
  dx1 = ps[i][0] - ps[i - 1][0]
  dy1 = ps[i][1] - ps[i - 1][1]
  dx2 = ps[i + 1][0] - ps[i][0]
  dy2 = ps[i + 1][1] - ps[i][1]
  dx = ps[i + 1][0] - ps[i - 1][0]
  dy = ps[i + 1][1] - ps[i - 1][1]
  res = min(res, abs(dx1 * dy2 - dy1 * dx2) / (dx * dx + dy * dy) ** 0.5)

print(res / 2)
