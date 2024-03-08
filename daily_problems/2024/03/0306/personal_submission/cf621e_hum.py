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


n, b, k, x = map(int, input().split())
a = list(map(int, input().split()))
cnt = [0] * 10
for v in a:
  cnt[v] += 1

grid = [[0] * x for _ in range(x)]
for i in range(x):
  for j in range(10):
    grid[i][(i * 10 + j) % x] += cnt[j]

print(matrix_pow(grid, b)[0][k])
