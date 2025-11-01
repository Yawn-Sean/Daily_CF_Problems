# Submission link: https://codeforces.com/gym/104873/submission/346438206
def main(): 
    M = 10 ** 5
    mod = 998244353
    
    dp = [[0] * (M + 1) for _ in range(450)]
    dp[0][0] = 1
    
    for i in range(1, 450):
        for j in range(M + 1):
            dp[i][j] += dp[i - 1][j]
            if j >= i: dp[i][j] += dp[i][j - i]
            dp[i][j] %= mod
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        ans = 0
        
        for i in range(1, 450):
            if (n + i) % 2 == 0 and i * i <= n:
                ans += dp[i][(n - i * i) // 2]
        
        ans %= mod
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))