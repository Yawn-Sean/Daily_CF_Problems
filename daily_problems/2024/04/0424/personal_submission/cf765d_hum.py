n = int(input())
f = list(map(int, input().split()))
g = [0] * (n + 1)
h = [0] * (n + 1)
m = 0
for i in range(1, n + 1):
  x = f[i - 1]
  if g[x] == 0:
    m += 1
    g[i] = m
    h[m] = x
    g[x] = m
  elif h[g[x]] == x:
    g[i] = g[x]
  else:
    exit(print(-1))

print(m)
print(*g[1:])
print(*h[1:m + 1])
