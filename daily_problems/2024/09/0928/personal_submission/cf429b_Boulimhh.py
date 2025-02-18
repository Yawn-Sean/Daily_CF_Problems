"""
思路： 这题看🐏神的思路。

用dp记录以某点为中心的最大值， 分别记录四个方向，左上， 右上， 左下， 右下。

再依次枚举以每个点当作中心时的情况， 取其最大值。 
"""
#python代码：
n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

dp0 = [[0] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        x = 0
        if i: x = max(x, dp0[i - 1][j])
        if j: x = max(x, dp0[i][j - 1])
        dp0[i][j] = x + grid[i][j]

dp1 = [[0] * m for _ in range(n)]

for i in range(n):
    for j in range(m - 1, -1, -1):
        x = 0
        if i: x = max(x, dp1[i - 1][j])
        if j < m - 1: x = max(x, dp1[i][j + 1])
        dp1[i][j] = x + grid[i][j]

dp2 = [[0] * m for _ in range(n)]

for i in range(n - 1, -1, -1):
    for j in range(m):
        x = 0
        if i < n - 1: x = max(x, dp2[i + 1][j])
        if j: x = max(x, dp2[i][j - 1])
        dp2[i][j] = x + grid[i][j]

dp3 = [[0] * m for _ in range(n)]

for i in range(n - 1, -1, -1):
    for j in range(m - 1, -1, -1):
        x = 0
        if i < n - 1: x = max(x, dp3[i + 1][j])
        if j < m - 1: x = max(x, dp3[i][j + 1])
        dp3[i][j] = x + grid[i][j]

ans = 0
for i in range(1, n - 1):
    for j in range(1, m - 1):
        ans = max(ans, dp0[i - 1][j] + dp1[i][j + 1] + dp2[i][j - 1] + dp3[i + 1][j])
        ans = max(ans, dp0[i][j - 1] + dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j + 1])

print(ans)
