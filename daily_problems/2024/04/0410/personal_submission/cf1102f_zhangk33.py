# Submission link: https://codeforces.com/contest/1102/submission/255971934

II = lambda: int(input())
MII = lambda: map(int, input().split())
LII = lambda: list(MII())
n, m = MII()
grid = [LII() for _ in range(n)]

# 预处理出每行对应元素间的最小差值
inf = 10 ** 9
r_diff = [[inf] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        if i != j:
            r_diff[i][j] = min(abs(grid[i][idx] - grid[j][idx]) for idx in range(m))

def p(msk, i, j):
    return (msk * n + i) * n + j

f = [0] * (n * n << n)
for i in range(n):
    f[p(1<<i, i, i)] = inf

# 状压dp计算不考虑错位项的结果
for msk in range(1 << n):
    for i in range(n):
        for j in range(n):
            if f[p(msk, i, j)]:
                old = f[p(msk, i, j)]
                for nj in range(n):
                    if msk >> nj & 1 == 0:
                        new_status = p(msk | (1 << nj), i, nj)
                        f[new_status] = max(f[new_status], min(old, r_diff[j][nj]))
# 枚举首行和末行的组合
ans = 0
for i in range(n):
    for j in range(n):
        cur = f[p((1 << n) - 1, i, j)]
        # 还要考虑错位的情况
        for idx in range(m-1):
            cur = min(cur, abs(grid[j][idx] - grid[i][idx+1]))
        ans = max(ans, cur)
print(ans)
