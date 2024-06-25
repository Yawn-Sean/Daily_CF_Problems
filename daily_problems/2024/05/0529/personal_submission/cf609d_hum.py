import sys

input = lambda: sys.stdin.readline().rstrip()

n, m, k, s = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
t, c = [], []
for i in range(m):
  x, y = map(int, input().split())
  t.append(x)
  c.append(y)


def check(mid):
  min_a = a[:mid + 1].index(min(a[:mid + 1]))
  min_b = b[:mid + 1].index(min(b[:mid + 1]))
  tmp = []
  for i in range(m):
    if t[i] == 1:
      tmp.append(a[min_a] * c[i])
    else:
      tmp.append(b[min_b] * c[i])
  tmp.sort()

  return sum(tmp[:k]) <= s


l, r = 0, n - 1
while l < r:
  mid = l + r >> 1
  if check(mid):
    r = mid
  else:
    l = mid + 1

if not check(l):
  print(-1)
else:
  print(l + 1)
  min_a = a[:l + 1].index(min(a[:l + 1]))
  min_b = b[:l + 1].index(min(b[:l + 1]))
  tmp = []
  for i in range(m):
    if t[i] == 1:
      tmp.append((a[min_a] * c[i], i, min_a))
    else:
      tmp.append((b[min_b] * c[i], i, min_b))
  tmp.sort()

  for i in range(k):
    print(tmp[i][1] + 1, tmp[i][2] + 1)
