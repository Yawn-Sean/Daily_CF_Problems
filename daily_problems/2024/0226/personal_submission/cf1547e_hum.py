from math import inf

q = int(input())
for _ in range(q):
  input()
  n, k = map(int, input().split())
  a = list(map(int, input().split()))
  t = list(map(int, input().split()))
  res = [inf] * (n + 2)
  for x, y in zip(a, t):
    res[x] = y
  for i in range(1, n + 1):
    res[i] = min(res[i - 1] + 1, res[i])
  for i in range(n, 0, -1):
    res[i] = min(res[i + 1] + 1, res[i])
  print(*res[1:n + 1])
