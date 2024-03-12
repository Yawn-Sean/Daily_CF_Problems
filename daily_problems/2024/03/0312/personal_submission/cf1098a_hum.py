n = int(input())
p = list(map(lambda x: int(x) - 1, input().split()))
p.insert(0, 0)
v = list(map(int, input().split()))
inf = float('inf')
a = [inf] * n
su = [0] * n
si = [0] * n
res = 0
for u in range(n - 1, -1, -1):
  if v[u] != -1:
    a[p[u]] = min(a[p[u]], v[u])
    su[p[u]] += v[u]
    si[p[u]] += 1
  else:

    if v[p[u]] > a[u]:
      print(-1)
      exit()
    if a[u] == inf:
      a[u] = v[p[u]]
    res += a[u] - v[p[u]]
    res += su[u] - a[u] * si[u]

print(res + v[0])
