# Submission link: https://codeforces.com/gym/106020/submission/380184122
def main():
    dp = [[0] * 20 for _ in range(20)]
    dp[0][0] = 1
    
    for i in range(1, 20):
        dp[0][i] = i * dp[0][i - 1]
    
    for i in range(1, 20):
        for j in range(20):
            if i + j <= 19:
                dp[i][j] = dp[i - 1][j] * j
                if i >= 2:
                    dp[i][j] += dp[i - 2][j + 1] * (i - 1)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        k -= 1
        
        v = fmin(n, n % 2 + 18)
        used = [0] * v
        
        res = [0] * v
        
        x, y = v, 0
        for i in range(v):
            for j in range(v):
                if used[j] or j == i: continue
                
                if used[i] and j < i:
                    nx, ny = x, y - 1
                elif used[i] or j < i:
                    nx, ny = x - 1, y
                else:
                    nx, ny = x - 2, y + 1
                
                if dp[nx][ny] <= k:
                    k -= dp[nx][ny]
                else:
                    x = nx
                    y = ny
                    used[j] = 1
                    res[i] = j
                    break
        
        ans = [0] * n
        
        for i in range(n // 2):
            ans[i * 2] = i * 2 + 1
            ans[i * 2 + 1] = i * 2
        
        for i in range(v):
            ans[n - v + i] = n - v + res[i]
        
        outs.append(' '.join(str(x + 1) for x in ans))
    
    print('\n'.join(outs))