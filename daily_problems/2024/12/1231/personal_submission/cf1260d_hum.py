import sys

input = lambda: sys.stdin.readline().rstrip()
m, n, k, t = map(int, input().split())
a = list(map(int, input().split()))
a.sort(reverse=True)
traps = []
for _ in range(k):
  l, r, d = map(int, input().split())
  traps.append((l, r, d))


def check(x):
  if x == 0:
    return True
  diff = [0] * (n + 2)
  m_a = a[x - 1]
  for l, r, d in traps:
    if d > m_a:
      diff[l] += 1
      diff[r + 1] -= 1
  acc = 0
  for i in range(1, n + 2):
    diff[i] += diff[i - 1]
    if diff[i] != 0:
      acc += 3
    else:
      acc += 1
  return acc <= t


l, r = 0, m
while l < r:
  mid = (l + r + 1) // 2
  if check(mid):
    l = mid
  else:
    r = mid - 1

print(l)

