n, k = map(int, input().split())
k -= 1
a = list(range(1, n + 1))


def dfs(l, r):
  global k
  if k == 0 or l + 1 >= r:
    return
  k -= 2
  m = l + r >> 1
  a[m - 1], a[m] = a[m], a[m - 1]
  dfs(l, m)
  dfs(m, r)


dfs(0, n)
if k != 0:
  print(-1)
else:
  print(*a)
