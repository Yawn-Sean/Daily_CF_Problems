# 枚举k*k的左上角，二维差分计算贡献的黑色行/列数
# 快读板子
import sys
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())

# 二维差分模版
class Diff:
    def __init__(self, m, n):
        self.m = m
        self.n = n
        self.diff = [[0] * (n + 2) for _ in range(m + 2)]

    def add(self, r1, c1, r2, c2, c):
        diff = self.diff
        diff[r1 + 1][c1 + 1] += c
        diff[r1 + 1][c2 + 2] -= c
        diff[r2 + 2][c1 + 1] -= c
        diff[r2 + 2][c2 + 2] += c

    def get(self):
        diff = self.diff
        for i in range(1, self.m + 1):
            for j in range(1, self.n + 1):
                diff[i][j] += diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1]
        diff = diff[1:-1]
        for i, row in enumerate(diff):
            diff[i] = row[1:-1]
        return diff

n, k = RII()
matrix = []
for _ in range(n):
    matrix.append(list(RS()))

def solve():
    ans = 0
    diff = Diff(n, n)
    # 处理行
    for i, row in enumerate(matrix):
        # 寻找最左右的黑
        l, r = 0, n - 1
        while l < n and row[l] == 'W':
            l += 1
        if l == n:
            ans += 1
        else:
            while r >= 0 and row[r] == 'W':
                r -= 1
            if r - l + 1 <= k:
                # 左上角
                lu_x, lu_y = max(0, i - k + 1), max(0, r - k + 1)
                # 右下角
                rd_x, rd_y = i, l
                diff.add(lu_x, lu_y, rd_x, rd_y, 1)

    # 列
    for i in range(n):
        # 寻找最上下的黑
        u, d = 0, n - 1
        while u < n and matrix[u][i] == 'W':
            u += 1
        if u == n:
            ans += 1
        else:
            while d >= 0 and matrix[d][i] == 'W':
                d -= 1
            if d - u + 1 <= k:
                # 左上角
                lu_x, lu_y = max(0, d - k + 1), max(0, i - k + 1),
                # 右下角
                rd_x, rd_y = u, i
                diff.add(lu_x, lu_y, rd_x, rd_y, 1)

    s = diff.get()
    mx = 0
    for i, row in enumerate(s):
        for j, x in enumerate(row):
            if x > mx:
                mx = x
    return ans + mx


print(solve())