# Submission link: https://codeforces.com/gym/103940/submission/364281819
def main(): 
    n = II()
    mod = 10 ** 9 + 7
    
    dp = [0] * (n + 1)
    acc = [0] * (n + 1)
    
    dp[1] = acc[1] = 1
    
    for i in range(2, n + 1):
        dp[i] = (acc[i - 1] - acc[i - i // 2 - 1]) % mod
        acc[i] = (acc[i - 1] + dp[i]) % mod
    
    print(dp[n])