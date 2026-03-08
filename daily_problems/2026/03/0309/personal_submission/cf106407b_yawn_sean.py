# Submission link: https://codeforces.com/gym/106407/submission/365852687
def main(): 
    t = II()
    outs = []
    
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        n = II()
        if n * (n + 1) // 2 % 2: outs.append(0)
        else:
            M = n * (n + 1) // 4
            dp = [[0] * (M + 1) for _ in range(n // 2 + 2)]
            dp[0][0] = 1
            
            for x in range(n + 1):
                for i in range(n // 2 + 1, 0, -1):
                    for j in range(x, M + 1):
                        dp[i][j] += dp[i - 1][j - x]
                        dp[i][j] %= mod
            
            n += 1
            ans = dp[n // 2][M] + dp[n - n // 2][M]
            ans = ans * (mod + 1) // 2 % mod
            
            for x in range(1, n // 2 + 1):
                ans = ans * x % mod
            
            for x in range(1, n - n // 2 + 1):
                ans = ans * x % mod
            
            outs.append(ans)
    
    print('\n'.join(map(str, outs)))