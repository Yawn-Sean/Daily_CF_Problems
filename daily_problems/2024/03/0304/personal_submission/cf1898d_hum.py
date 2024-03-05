t = int(input())
for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  b = list(map(int, input().split()))
  tmp = [[min(x, y), max(x, y)] for x, y in zip(a, b)]
  res1 = sum(x[1] - x[0] for x in tmp)
  m1 = max(x[0] for x in tmp)
  m2 = min(x[1] for x in tmp)
  res2 = res1 + 2 * m1 - 2 * m2
  print(max(res1, res2))
