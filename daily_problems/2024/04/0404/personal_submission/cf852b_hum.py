def matrix_mul(A, B, mod=10 ** 9 + 7):
  assert len(A[0]) == len(B)
  h, mid = len(A), len(A[0])
  w = len(B[0])
  res = [[0] * w for _ in range(h)]
  for i in range(h):
    for k in range(mid):
      for j in range(w):
        res[i][j] += A[i][k] * B[k][j]
        res[i][j] %= mod
  return res


def matrix_pow(A, k, mod=10 ** 9 + 7):
  assert len(A) == len(A[0])
  n = len(A)
  b = A
  res = [[0] * n for _ in range(n)]
  for i in range(n):
    res[i][i] = 1
  while k:
    if k % 2:
      res = matrix_mul(res, b, mod)
    b = matrix_mul(b, b, mod)
    k //= 2
  return res


n, l, m = map(int, input().split())

c1 = list(map(int, input().split()))
c2 = list(map(int, input().split()))
c3 = list(map(int, input().split()))
a = [[0] for _ in range(m)]
for i in c1:
  a[i % m][0] += 1

t = [0] * m
for i in c2:
  t[i % m] += 1

mat = [[0] * m for _ in range(m)]
for i in range(m):
  for j in range(m):
    mat[i][j] = t[i - j]

mod = 10 ** 9 + 7
mat = matrix_pow(mat, l - 2, mod=mod)
a = matrix_mul(mat, a)

res = 0
for x, y in zip(c2, c3):
  res += a[(m - x - y) % m][0]

print(res % mod)
