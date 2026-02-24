# Submission link: https://codeforces.com/gym/103870/submission/364193748
def main(): 
    n, mod = MII()
    f = Factorial(n, mod)
    
    dp = [0] * (n + 1)
    
    p1 = pow(3, -1, mod)
    p2 = 2 * p1 % mod
    
    v = 2
    v1 = p1
    v2 = p2
    
    for i in range(2, n + 1):
        v = v * 2 % mod
        v1 = v1 * p1 % mod
        v2 = v2 * p2 % mod
    
        for j in range(i):
            dp[i] += f.combi(i, j) * dp[j]
            dp[i] %= mod
    
        dp[i] = dp[i] * pow(v - 2, -1, mod) % mod
        
        dp[i] += pow(3 * v2 - 6 * v1, -1, mod)
        dp[i] %= mod
    
    print(*dp[1:])