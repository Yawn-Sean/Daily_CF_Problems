# Submission link: https://codeforces.com/gym/106103/submission/390164305
def main():
    n = II()
    mod = 10 ** 9 + 7
    
    combs = [[0] * (n + 1) for _ in range(n + 1)]
    
    for i in range(n + 1):
        combs[i][0] = 1
        combs[i][i] = 1
        
        for j in range(1, i):
            combs[i][j] = (combs[i - 1][j] + combs[i - 1][j - 1]) % mod
    
    ans = 0
    
    dp1 = [[0] * (n + 1) for _ in range(n + 1)]
    dp2 = [[0] * (n + 1) for _ in range(n + 1)]
    
    dp1[0][0] = 1
    dp2[0][0] = 1
    
    for i in range(n + 1):
        for j in range(n + 1):
            for k in range(i + 1, n + 1):
                dp2[k][j] += dp1[i][j] * combs[k][i]
                dp2[k][j] %= mod
            
            for k in range(j + 1, n + 1):
                dp1[i][k] += dp2[i][j] * combs[k][j]
                dp1[i][k] %= mod
    
    print((dp1[n][n] + dp2[n][n]) % mod)