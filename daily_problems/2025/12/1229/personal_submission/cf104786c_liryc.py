'''
https://codeforces.com/gym/104786/submission/355650211
'''
def solve(n: int, x: int, y: int) -> int: 
    MOD = 1000000007
    
    x = n - x
    y = n - y
    
    dp = [[0] * (x + 1) for _ in range(x + 1)]
    
    r2 = MOD + 1 >> 1
    
    for i in range(1, x + 1):
        for j in range(i):
            v = dp[i - 1][abs(j - 1)]
            if j + 1 <= i - 1: 
                v += dp[i - 1][j + 1]
            dp[i][j] = (v * r2 + 1) % MOD
    
    return dp[x][y]
