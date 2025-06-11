import sys

input = lambda: sys.stdin.readline().rstrip()
n, t = map(int, input().split())
a = []
for i in range(n):
  x, y = map(int, input().split())
  a.append((y, x, i))

a.sort()


def check(k):
  acc = 0
  cnt = 0
  for i in range(n):
    if a[i][1] >= k:
      acc += a[i][0]
      cnt += 1
      if acc > t:
        return False
      if cnt == k:
        return True

  return cnt >= k


l, r = 0, n
while l < r:
  mid = l + r + 1 >> 1
  if check(mid):
    l = mid
  else:
    r = mid - 1

print(l)
print(l)
cur = [(x, i) for x, y, i in a if y >= l]
cur.sort()
cur = [cur[i][1] + 1 for i in range(l)]
print(*cur)
