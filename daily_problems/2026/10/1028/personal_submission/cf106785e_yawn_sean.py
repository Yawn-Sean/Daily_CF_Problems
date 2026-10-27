# Submission link: https://codeforces.com/gym/106785/submission/396299046
def main():
    t = II()
    outs = []
    
    mod = 998244353
    
    for _ in range(t):
        n, m = MII()
        grid = [[1 if c == '.' else 0 for c in I()] for _ in range(n)]
        
        dp0 = [[0] * m for _ in range(n)]
        dp1 = [[0] * m for _ in range(n)]
        
        dp0[0][0] = 1 if grid[0][0] else 0
    
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    if i: dp0[i][j] = dp0[i - 1][j]
                    if j:
                        if grid[i][j - 1] == 0:
                            dp0[i][j] += dp1[i - 1][j]
                        dp1[i][j] = dp0[i][j - 1] + dp1[i][j - 1]
                    dp0[i][j] %= mod
                    dp1[i][j] %= mod
        
        outs.append((dp0[-1][-1] + dp1[-1][-1]) % mod)
    
    print('\n'.join(map(str, outs)))