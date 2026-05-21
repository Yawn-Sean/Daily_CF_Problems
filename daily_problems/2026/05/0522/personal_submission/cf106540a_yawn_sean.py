# Submission link: https://codeforces.com/gym/106540/submission/375455889
def main():
    t = II()
    outs = []
    
    mod = 998244353
    
    for _ in range(t):
        n, k = MII()
        kmp = prep(I())
        
        dp = [0] * (k + 1)
        dp[0] = 1
        
        for i in range(k):
            for j in range(n):
                if kmp[j] == 0 and i + j + 1 <= k:
                    dp[i + j + 1] = (dp[i + j + 1] + dp[i]) % mod
        
        outs.append(dp[k])
    
    print('\n'.join(map(str, outs)))