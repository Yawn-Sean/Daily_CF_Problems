n, m = map(int, input().split())
a = list(map(int, input().split()))
idx = [[] for _ in range(m)]
for i in range(n):
  idx[a[i] % m].append(i)

k = n // m

res = 0

stack = []
for i in range(2 * m):
  x = i % m
  while stack and len(idx[x]) < k:
    j = stack.pop()
    v = (x - a[j]) % m
    a[j] += v
    res += v
    idx[x].append(j)

  while len(idx[x]) > k:
    stack.append(idx[x].pop())

print(res)

print(*a)
