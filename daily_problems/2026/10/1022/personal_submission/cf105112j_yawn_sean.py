# Submission link: https://codeforces.com/gym/105112/submission/395470333
def main():
    n = II()
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)
    
    ans = inf
    
    for i in range(n):
        for j in range(i):
            dx = xs[i] - xs[j]
            dy = ys[i] - ys[j]
            
            vx = -dy
            vy = dx
            
            grid = [[0] * n for _ in range(n)]
            
            for x in range(n):
                for y in range(n):
                    grid[x][y] += abs((xs[x] - xs[y]) * dx + (ys[x] - ys[y]) * dy)
                    grid[x][y] += abs((xs[x] - xs[y]) * vx + (ys[x] - ys[y]) * vy)
            
            dp = [[inf] * (1 << n) for _ in range(n)]
            
            for x in range(n):
                dp[x][1 << x] = 0
            
            for msk in range(1 << n):
                for x in range(n):
                    if dp[x][msk] < inf:
                        for y in range(n):
                            if msk >> y & 1: continue
                            nmsk = msk | (1 << y)
                            dp[y][nmsk] = fmin(dp[y][nmsk], dp[x][msk] + grid[x][y])
            
            res = inf
            for x in range(n):
                res = fmin(res, dp[x][-1])
            
            ans = fmin(ans, res / math.hypot(dx, dy))
    
    print(ans)