# Submission link: https://codeforces.com/gym/106841/submission/399782824
def main(): 
    W = 232792560
    
    m, n, k = MII()
    sx, sy, ex, ey = GMI()
    grid = [[0] * m for _ in range(n)]
    
    for _ in range(k):
        x1, y1, x2, y2 = MII()
        w = W // ((x2 - x1 + 1) * (y2 - y1 + 1))
        for i in range(x1 - 1, x2):
            for j in range(y1 - 1, y2):
                grid[i][j] += w
    
    for i in range(sx, ex + 1):
        for j in range(sy, ey + 1):
            if i == sx and j == sy: continue
            res = inf
            if i > sx: res = fmin(res, grid[i - 1][j])
            if j > sy: res = fmin(res, grid[i][j - 1])
            grid[i][j] += res
    
    mod = 10 ** 9 + 7
    print(grid[ex][ey] * pow(W, -1, mod) % mod)