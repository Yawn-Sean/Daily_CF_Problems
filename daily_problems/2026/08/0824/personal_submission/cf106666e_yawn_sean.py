# Submission link: https://codeforces.com/gym/106666/submission/388120297
def main():
    n = II()
    mod = 10 ** 9 + 7
    
    dp = [0] * (n + 1)
    dp[0] = 2
    
    for i in range(1, n + 1):
        v = 1
        while i >= v:
            dp[i] += dp[i - v]
            v *= 2
        dp[i] %= mod
    
    print(dp[n])