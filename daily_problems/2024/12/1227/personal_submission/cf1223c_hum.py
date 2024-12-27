import sys

input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
  n = int(input())
  p = list(map(int, input().split()))
  x, a = list(map(int, input().split()))
  y, b = list(map(int, input().split()))
  if x < y:
    x, y = y, x
    a, b = b, a
  k = int(input())
  p.sort(reverse=True)

  l, r = 0, n


  def check(k):
    cxy = 0
    cx = 0
    cy = 0
    for i in range(k):
      if (i + 1) % a == 0 and (i + 1) % b == 0:
        cxy += 1
      elif (i + 1) % a == 0:
        cx += 1
      elif (i + 1) % b == 0:
        cy += 1
    s = (sum(p[:cxy]) * (x + y)) // 100
    s += (sum(p[cxy:cxy + cx]) * x) // 100
    s += (sum(p[cxy + cx:cxy + cx + cy]) * y) // 100
    return s


  while l < r:
    mid = (l + r) // 2
    if check(mid) >= k:
      r = mid
    else:
      l = mid + 1

  if check(l) < k:
    print(-1)
  else:
    print(l)
