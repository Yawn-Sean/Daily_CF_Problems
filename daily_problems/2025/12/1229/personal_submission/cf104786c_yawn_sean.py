# Submission link: https://codeforces.com/gym/104786/submission/355494545
def main(): 
    mod = 10 ** 9 + 7
    n, x, y = MII()
    
    x = n - x
    y = n - y
    
    dp = [[0] * (x + 1) for _ in range(x + 1)]
    
    rev2 = (mod + 1) // 2
    
    for i in range(1, x + 1):
        for j in range(i):
            v = dp[i - 1][abs(j - 1)]
            if j + 1 <= i - 1: v += dp[i - 1][j + 1]
            dp[i][j] = (v * rev2 + 1) % mod
    
    print(dp[x][y])