# Submission link: https://codeforces.com/gym/105668/submission/351367292
def main(): 
    t = II()
    outs = []
    
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    
    for _ in range(t):
        n, m = MII()
        grid = [LII() for _ in range(n)]
        
        tmp = []
        res = 0
        
        for i in range(n):
            for j in range(m):
                res ^= grid[i][j] & 1
                tmp.append((grid[i][j] * n + i) * m + j)
        
        tmp.sort()
        
        to_fill = [[-1] * m for _ in range(n)]
        
        for x in tmp:
            msk = x % (n * m)
            i, j = divmod(msk, m)
            
            val = -1
            for di, dj in dirs:
                if 0 <= i + di < n and 0 <= j + dj < m:
                    val = fmax(val, to_fill[i + di][j + dj])
            
            to_fill[i][j] = val + 1
            
            res ^= (val + 1) & 1
        
        outs.append('Yes' if res else 'No')
    
    print('\n'.join(outs))