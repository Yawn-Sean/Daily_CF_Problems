import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

n, b = map(int, input().split())
finish_time = 0
q = deque()
res = [-1] * n
for i in range(n):
  t, d = map(int, input().split())
  while q and q[0][0] >= finish_time:
    s, e, idx = q.popleft()
    res[idx] = s + e
    finish_time = res[idx]
  if len(q) < b:
    q.append((t, d, i))
  else:
    if t >= finish_time:
      s, e, idx = q.popleft()
      res[idx] = max(finish_time, s) + e
      finish_time = res[idx]
      q.append((t, d, i))

while q:
  s, e, idx = q.popleft()
  res[idx] = max(finish_time, s) + e
  finish_time = res[idx]

print(*res)
