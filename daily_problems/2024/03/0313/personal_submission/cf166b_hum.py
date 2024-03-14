import bisect

n = int(input())
pts = []
for _ in range(n):
  x, y = map(int, input().split())
  pts.append((x, y))

l, r = pts.index(min(pts)), pts.index(max(pts))

if r > l:
  higher = pts[l:r + 1]
  lower = pts[r:] + pts[:l + 1]
else:
  higher = pts[l:] + pts[:r + 1]
  lower = pts[r:l + 1]
lower.reverse()

min_x, max_x = pts[l][0], pts[r][0]

m = int(input())
for _ in range(m):
  x, y = map(int, input().split())
  if x <= min_x or x >= max_x:
    exit(print('NO'))

  p1 = bisect.bisect_left(higher, (x, y))
  x1, y1 = higher[p1 - 1]
  x2, y2 = higher[p1]
  if (x - x1) * (y2 - y1) <= (y - y1) * (x2 - x1):
    exit(print('NO'))

  p2 = bisect.bisect_left(lower, (x, y))
  x1, y1 = lower[p2 - 1]
  x2, y2 = lower[p2]
  if (x - x1) * (y2 - y1) >= (y - y1) * (x2 - x1):
    exit(print('NO'))

print("YES")
