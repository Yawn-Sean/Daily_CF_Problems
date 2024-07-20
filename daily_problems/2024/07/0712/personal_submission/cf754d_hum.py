import sys

input = lambda: sys.stdin.readline().rstrip()

n, k = map(int, input().split())
seg = []
for i in range(n):
  l, r = map(int, input().split())
  seg.append((l, r, i))

seg.sort(key=lambda x: x[1], reverse=True)

sl = SortedList()
res = []
m, idx = 0, -1
for l, r, i in seg:
  sl.add(l)
  res.append((l, i))
  if len(sl) >= k:
    ll = sl[k - 1]
    if ll <= r and m < r - ll + 1:
      m = r - ll + 1
      idx = len(res)

res = res[:idx]

res.sort(key=lambda x: x[0])
print(m)
if m == 0:
  print(*[i for i in range(1, k + 1)])
  exit()
for i in range(k):
  print(res[i][1] + 1, end=' ')
