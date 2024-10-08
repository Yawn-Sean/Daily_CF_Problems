import sys
input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for idx in range(t):
  n = int(input())
  a = list(map(lambda x: int(x) - 1, input().split()))
  b = list(map(lambda x: int(x) - 1, input().split()))
  p = [0] * n
  for i in range(n):
    p[a[i]] = i
  vis = [0] * n

  k = 0

  for i in range(n):
    u = i
    if not vis[u]:
      cnt = 0
      while not vis[u]:
        vis[u] = 1
        u = p[b[u]]
        cnt += 1
      k += cnt // 2
  print(2 * k * (n - k))
