# Submission link: https://codeforces.com/gym/106363/submission/362652863
def main(): 
    mod = 10 ** 9 + 7
    n, k = MII()
    
    def f(i, j):
        return i * (n + 1) + j
    
    dp = [[0] * (n + 1) * (n + 1) for _ in range(4)]
    ndp = [[0] * (n + 1) * (n + 1) for _ in range(4)]
    
    for i in range(n):
        dp[1][f(i, 0)] = 1
    
    for i in range(n - 1):
        for x in range(1, 4):
            for y in range(n - i):
                for z in range(fmax(i - 2, 0) + 1):
                    ndp[1][f(0, z)] += dp[x][f(y, z)]
                    ndp[1][f(y, z)] -= dp[x][f(y, z)]
                    if x < 3:
                        ndp[x + 1][f(y, z)] += dp[x][f(y, z)]
                        ndp[x + 1][f(n - 1 - i, z)] -= dp[x][f(y, z)]
                    else:
                        ndp[3][f(y, z + 1)] += dp[x][f(y, z)]
                        ndp[3][f(n - 1 - i, z + 1)] -= dp[x][f(y, z)]
        
        i += 1
        for x in range(1, 4):
            for y in range(n - i):
                for z in range(fmax(i - 2, 0) + 1):
                    ndp[x][f(y + 1, z)] += ndp[x][f(y, z)]
                    dp[x][f(y, z)] = ndp[x][f(y, z)] % mod
                    ndp[x][f(y, z)] = 0
    
    ans = 0
    for x in range(4):
        ans += dp[x][f(0, k)]
        ans %= mod
    
    print(ans)