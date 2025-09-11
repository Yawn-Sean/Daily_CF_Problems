# Submission link: https://codeforces.com/gym/100008/submission/338010052
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, w, l = MII()
        
        grid = [[0] * (n + 1) for _ in range(n + 1)]
        
        for _ in range(w):
            x, y = MII()
            grid[x][y] = 1
        
        for i in range(n):
            for j in range(n + 1):
                grid[i + 1][j] += grid[i][j]
        
        for i in range(n + 1):
            for j in range(n):
                grid[i][j + 1] += grid[i][j]
        
        ans = [[0] * (n + 1) for _ in range(n + 1)]
        res = 0
        
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                v = ans[i - 1][j - 1] + 1
                
                while grid[i][j] - grid[i - v][j] - grid[i][j - v] + grid[i - v][j - v] > l:
                    v -= 1
                
                ans[i][j] = v
                res = fmax(res, v)
        
        outs.append(res * res)
    
    print('\n'.join(map(str, outs)))