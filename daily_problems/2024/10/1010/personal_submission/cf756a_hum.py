n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))
b = list(map(int, input().split()))

res = 0
vis = [0] * n
for i in range(n):
  if not vis[i]:
    res += 1
    u = i
    while not vis[u]:
      vis[u] = 1
      u = a[u]

if res == 1:
  res -= 1
c = b.count(1)

print(res + 1 - c % 2)
