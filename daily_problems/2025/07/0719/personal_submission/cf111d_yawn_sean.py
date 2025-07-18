# Submission link: https://codeforces.com/contest/111/submission/329657371
def main():
    n, m, k = MII()
    mod = 10 ** 9 + 7
    fac = Factorial(10 ** 6, mod)
    
    if m == 1:
        print(pow(k, n, mod))
        exit()
    
    dp = [0] * (n + 1)
    
    dp[0] = 1
    for i in range(1, n + 1):
        for j in range(i, 0, -1):
            dp[j] = (dp[j - 1] + j * dp[j]) % mod
        dp[0] = 0
    
    for i in range(n + 1):
        dp[i] = dp[i] * fac.fac(i) % mod
    
    ans = 0
    for i in range(n + 1):
        val = pow(i, n * (m - 2), mod)
        for j in range(i, n + 1):
            ans += fac.combi(k, i) * fac.combi(k - i, 2 * (j - i)) % mod * fac.combi(2 * (j - i), j - i) % mod * dp[j] % mod * dp[j] % mod * val % mod
            if ans >= mod:
                ans -= mod
    
    print(ans)