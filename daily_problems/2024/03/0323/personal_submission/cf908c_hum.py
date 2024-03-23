n, r = map(int, input().split())
x = list(map(int, input().split()))

res = [r * 1.0] * n

for i in range(1, n):
  for j in range(i):
    delt_y = 4 * r ** 2 - (abs(x[j] - x[i])) ** 2
    if delt_y >= 0:
      res[i] = max(res[i], res[j] + delt_y ** 0.5)

print(*res)
