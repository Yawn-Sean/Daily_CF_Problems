'''
https://codeforces.com/gym/103940/submission/364412818
'''
def solve(k):
    MOD = 1000000007
    dp = [0] * (k + 1)
    dp[1] = 1
    prefix = [0] * (k + 1)
    prefix[1] = 1
    for t in range(2, k + 1):
        half = t + 1 >> 1
        if half >= 1:
            dp[t] = (prefix[t - 1] - prefix[half - 1]) % MOD
        else:
            dp[t] = 0
        prefix[t] = (prefix[t - 1] + dp[t]) % MOD
    return dp[k]
