import sys
from collections import deque
from math import gcd

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  pre = [(i - 1) % n for i in range(n)]
  suf = [(i + 1) % n for i in range(n)]

  vis = [0] * n

  res = []
  dq = deque(list(range(n)))
  while dq:
    u = dq.popleft()
    if vis[u]:
      continue
    v = suf[u]
    if gcd(a[u], a[v]) == 1:
      res.append(v + 1)
      vis[v] = 1
      pre[suf[v]] = pre[v]
      suf[pre[v]] = suf[v]
      dq.append(u)

  print(len(res), *res)
