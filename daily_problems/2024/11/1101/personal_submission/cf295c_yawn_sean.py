# Submission link: https://codeforces.com/contest/295/submission/289075491
def main():
    mod = 10 ** 9 + 7
    combs = [[0] * 51 for _ in range(51)]

    for i in range(51):
        combs[i][0] = combs[i][i] = 1
        for j in range(1, i):
            combs[i][j] = combs[i - 1][j] + combs[i - 1][j - 1]
            if combs[i][j] >= mod:
                combs[i][j] -= mod

    n, k = MII()
    k //= 50

    nums = LII()
    c1 = c2 = 0

    for v in nums:
        if v == 50: c1 += 1
        else: c2 += 1

    dp = [[0] * (c2 + 1) for _ in range(c1 + 1)]
    dp[0][0] = 1

    vis = [[0] * (c2 + 1) for _ in range(c1 + 1)]
    vis[0][0] = 1

    ndp = [[0] * (c2 + 1) for _ in range(c1 + 1)]
    nvis = [[0] * (c2 + 1) for _ in range(c1 + 1)]

    for i in range(2 * n + 1):
        for x in range(c1 + 1):
            for y in range(c2 + 1):
                if vis[x][y] == 0: continue
                
                for nx in range(c1 - x + 1):
                    for ny in range(c2 - y + 1):
                        if nx + ny * 2 <= k:
                            ndp[x + nx][y + ny] += dp[x][y] * combs[c1 - x][nx] % mod * combs[c2 - y][ny] % mod
                            nvis[x+ nx][y + ny] = 1
                            if ndp[x + nx][y + ny] >= mod:
                                ndp[x + nx][y + ny] -= mod

        for x in range(c1 + 1):
            for y in range(c2 + 1):
                dp[x][y] = ndp[x][y]
                vis[x][y] = nvis[x][y]
                ndp[x][y] = 0
                nvis[x][y] = 0
        
        if vis[c1][c2]:
            print(2 * i + 1)
            print(dp[c1][c2])
            exit()
        
        for x in range(c1 + 1):
            for y in range(c2 + 1):
                if vis[x][y] == 0: continue
                
                for nx in range(x + 1):
                    for ny in range(y + 1):
                        if nx + ny * 2 <= k and (nx > 0 or ny > 0):
                            ndp[x - nx][y - ny] += dp[x][y] * combs[x][nx] % mod * combs[y][ny] % mod
                            nvis[x - nx][y - ny] = 1
                            if ndp[x - nx][y - ny] >= mod:
                                ndp[x - nx][y - ny] -= mod
        
        for x in range(c1 + 1):
            for y in range(c2 + 1):
                dp[x][y] = ndp[x][y]
                vis[x][y] = nvis[x][y]
                ndp[x][y] = 0
                nvis[x][y] = 0

    print(-1)
    print(0)