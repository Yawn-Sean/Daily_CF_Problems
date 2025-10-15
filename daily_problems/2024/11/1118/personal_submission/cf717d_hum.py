n, k = map(int, input().split())
prob = list(map(float, input().split()))


def mul(grid1, grid2):
  ans = [0] * 128
  for i in range(128):
    for j in range(128):
      ans[i ^ j] += grid1[i] * grid2[j]
  return ans


def quickPow(grid, n):
  if n == 1: return grid
  ans = quickPow(grid, n // 2)
  ans = mul(ans, ans)
  if n % 2: ans = mul(ans, grid)
  return ans


grid = [0] * 128

for i in range(k + 1):
  grid[i] = prob[i]

print(1 - quickPow(grid, n)[0])
