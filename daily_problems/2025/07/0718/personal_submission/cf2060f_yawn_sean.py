# Submission link: https://codeforces.com/contest/2060/submission/329347227
def main():
    K, mod = 10 ** 5, 998244353
    dp = [[0] * (K + 1) for _ in range(17)]
    
    dp[0][1] = 1
    
    for i in range(16):
        for j in range(K + 1):
            if dp[i][j]:
                for v in range(2 * j, K + 1, j):
                    dp[i + 1][v] += dp[i][j]
                    if dp[i + 1][v] >= mod:
                        dp[i + 1][v] -= mod
    
    f = Factorial(20, mod)
    
    t = II()
    outs = []
    
    for _ in range(t):
        k, n = MII()
        
        ans = [0] * k
        ans[0] = n
    
        for i in range(2, k + 1):
            cur = 1
            for j in range(17):
                cur = cur * (n + 1 - j) % mod
                ans[i - 1] += dp[j][i] * cur % mod * f.fac_inv(j + 1) % mod
                if ans[i - 1] >= mod:
                    ans[i - 1] -= mod
        
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))