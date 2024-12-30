n = 70
x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())
ps = [(x0, y0)]
for i in range(n):
  ps.append((ax * ps[-1][0] + bx, ay * ps[-1][1] + by))

res = 0
for i in range(n):
  for j in range(i, n):
    l = (ps[j][0] - ps[i][0]) + (ps[j][1] - ps[i][1])
    left = abs(xs - ps[i][0]) + abs(ys - ps[i][1])
    right = abs(xs - ps[j][0]) + abs(ys - ps[j][1])
    if t >= left + l or t >= right + l:
      res = max(res, j - i + 1)

print(res)
