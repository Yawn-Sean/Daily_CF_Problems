# Submission link: https://codeforces.com/contest/1031/submission/279399191
def main():
    n, k = MII()
    grid = [I() for _ in range(n)]

    dp = [2 * n] * (n * n)
    def f(x, y): return x * n + y

    dp[f(0, 0)] = 0

    for i in range(n):
        for j in range(n):
            if i and dp[f(i-1, j)] < dp[f(i, j)]:
                dp[f(i, j)] = dp[f(i-1, j)]
            if j and dp[f(i, j-1)] < dp[f(i, j)]:
                dp[f(i, j)] = dp[f(i, j-1)]
            dp[f(i, j)] += 0 if grid[i][j] == 'a' else 1

    cur = 0
    tmp = [f(0, 0)]
    for i in range(n):
        for j in range(n):
            if dp[f(i, j)] <= k:
                if i + j > cur:
                    cur = i + j
                    tmp = [f(i, j)]
                elif i + j == cur:
                    tmp.append(f(i, j))

    ans = ['a' * cur]
    ans.append('a' if dp[tmp[0]] <= k else grid[0][0])

    dirs = [(0, 1), (1, 0)]

    for _ in range(cur + 1, 2 * n - 1):
        ntmp = []
        nc = chr(ord('z') + 1)
        for msk in tmp:
            x, y = divmod(msk, n)
            for dx, dy in dirs:
                if x + dx < n and y + dy < n:
                    if grid[x+dx][y+dy] < nc:
                        nc = grid[x+dx][y+dy]
                        ntmp = [f(x + dx, y + dy)]
                    elif grid[x+dx][y+dy] == nc:
                        if f(x+dx, y+dy) != ntmp[-1]:
                            ntmp.append(f(x + dx, y + dy))
        ans.append(nc)
        tmp = ntmp

    print(''.join(ans))