import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
if m == n * (n - 1) // 2:
  print("NO")
  exit()

vis = set()
for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  vis.add(a * n + b)
  vis.add(b * n + a)

print("YES")


def f():
  for i in range(n):
    for j in range(i):
      if i * n + j not in vis:
        return (i, j)


x, y = f()
a = [0] * n
idx = 1
for i in range(n):
  if i != x and i != y:
    a[i] = idx
    idx += 1
a[x], a[y] = n - 1, n

b = a[:]
b[x] = n

print(*a)
print(*b)
