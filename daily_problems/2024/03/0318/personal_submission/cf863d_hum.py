import sys

input = lambda: sys.stdin.readline().rstrip()

n, q, m = map(int, input().split())
a = list(map(int, input().split()))
op = []
for _ in range(q):
  t, l, r = map(int, input().split())
  op.append((t, l - 1, r - 1))
op.reverse()

query = list(map(int, input().split()))

res = []
for x in query:
  cur = x - 1
  for t, l, r in op:
    if t == 1:
      if l <= cur <= r:
        cur = cur - 1
        if cur < l:
          cur = r
    else:
      if l <= cur <= r:
        cur = l + r - cur

  res.append(a[cur])

print(*res)
