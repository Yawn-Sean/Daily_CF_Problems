import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
  n, m, k, q = map(int, input().split())
  xs, ys = [], []
  for _ in range(q):
    x, y = map(int, input().split())
    xs.append(x)
    ys.append(y)
  setx = set()
  sety = set()
  res = 1
  mod = 998244353
  for i in range(q - 1, -1, -1):
    x, y = xs[i], ys[i]
    if x in setx and y in sety:
      continue
    if len(setx) == n or len(sety) == m:
      continue
    setx.add(x)
    sety.add(y)
    res = (res * k) % mod
  print(res)
