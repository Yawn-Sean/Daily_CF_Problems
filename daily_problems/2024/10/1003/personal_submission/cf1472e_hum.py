import sys

input = lambda: sys.stdin.readline().rstrip()

t = int(input())
outs = []
for _ in range(t):
  n = int(input())
  hs, ws = [], []
  for _ in range(n):
    h, w = map(int, input().split())
    h, w = min(h, w), max(h, w)
    hs.append(h)
    ws.append(w)
  res = [0] * n
  idx = sorted(range(n), key=lambda x: (hs[x], -ws[x]))
  min_idx = -1
  for i in idx:
    if min_idx == -1 or ws[min_idx] >= ws[i]:
      res[i] = -1
      min_idx = i
    else:
      res[i] = min_idx + 1
  print(*res)
