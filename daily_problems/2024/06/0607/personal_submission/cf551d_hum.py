n, k, l, m = map(int, input().split())

mat = [[1, 1], [1, 0]]

res = [[1, 0], [0, 1]]


def mul_mat(m1, m2):
  n = len(m1)
  res = [[0] * n for _ in range(n)]
  for i in range(n):
    for j in range(n):
      res[i][j] = sum(m1[i][k] * m2[k][j] for k in range(n)) % m

  return res


t = n - 1
while t > 0:
  if t & 1:
    res = mul_mat(res, mat)
  mat = mul_mat(mat, mat)
  t >>= 1

x = (res[0][0] + res[0][1] + res[1][0] + res[1][1]) % m

y = (pow(2, n, m) - x) % m

if k >= (1 << l):
  print(0)
  exit()
res = 1
for i in range(l):
  if (k >> i) & 1:
    res = (res * y) % m
  else:
    res = (res * x) % m

print(res % m)
