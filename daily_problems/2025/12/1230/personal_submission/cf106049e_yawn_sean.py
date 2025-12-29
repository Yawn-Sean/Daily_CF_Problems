# Submission link: https://codeforces.com/gym/106049/submission/355666587
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, q = MII()
        grid = [LII() for _ in range(n)]
        
        saved = [0] * (2 * n - 1)
        dp = [[0] * n for _ in range(n)]
        
        for _ in range(q):
            k, v = MII()
            k -= 2
            
            if saved[k]:
                dp[n - 1][n - 1] += v - saved[k]
                saved[k] = v
            else:
                saved[k] = v
                for i in range(n):
                    for j in range(n):
                        if saved[i + j] > 0:
                            grid[i][j] = saved[i + j]
                        dp[i][j] = grid[i][j]
                
                for i in range(n):
                    for j in range(n):
                        w = 0
                        if i: w = fmax(w, dp[i - 1][j])
                        if j: w = fmax(w, dp[i][j - 1])
                        dp[i][j] += w
            
            outs.append(dp[n - 1][n - 1])
    
    print('\n'.join(map(str, outs)))