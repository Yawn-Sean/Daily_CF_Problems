# Submission link: https://codeforces.com/gym/106178/submission/349817629
def main(): 
    n, k = MII()
    mod = 998244353
    
    n = fmin(n, k)
    
    dp = [0] * (k + 1)
    dp[0] = 1
    
    for i in range(1, n + 1):
        ndp = [0] * (k + 1)
        
        for j in range(k + 1):
            start = j * (i - 1) + 1
            end = j * (i - 1) + k
            
            left = (start + i - 1) // i
            right = end // i
            
            ndp[left] += dp[j]
            if right < k:
                ndp[right + 1] -= dp[j]
        
        for j in range(1, k + 1):
            ndp[j] += ndp[j - 1]
            ndp[j] %= mod
        
        dp = ndp
    
    print(sum(dp) % mod)