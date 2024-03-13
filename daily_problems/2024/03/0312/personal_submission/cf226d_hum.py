n, m = map(int, input().split())
grid = []
for _ in range(n):
  grid.append(list(map(int, input().split())))

f_x = [0] * n
f_y = [0] * m

sum_x = [0] * n
sum_y = [0] * m

for i in range(n):
  for j in range(m):
    sum_x[i] += grid[i][j]
    sum_y[j] += grid[i][j]

while min(sum_x) < 0 or min(sum_y) < 0:
  for i in range(n):
    if sum_x[i] < 0:
      f_x[i] ^= 1
      sum_x[i] = -sum_x[i]
      for j in range(m):
        sum_y[j] -= grid[i][j] * 2
        grid[i][j] = -grid[i][j]

  for i in range(m):
    if sum_y[i] < 0:
      f_y[i] ^= 1
      sum_y[i] = -sum_y[i]
      for j in range(n):
        sum_x[j] -= grid[j][i] * 2
        grid[j][i] = -grid[j][i]

print(sum(f_x), *(i + 1 for i in range(n) if f_x[i]))
print(sum(f_y), *(i + 1 for i in range(m) if f_y[i]))
