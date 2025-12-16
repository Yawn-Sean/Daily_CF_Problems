# Submission link: https://codeforces.com/gym/105845/submission/353676553
def main(): 
    n = II()
    mod = 10 ** 9 + 7
    
    dp = [0] * (n + 1)
    dp[0] = 1
    
    ans = 0
    
    for i in range(1, n + 1):
        ndp = [0] * (n + 1)
        
        cur = [0] * i
        pre = 0
        
        for j in range(n + 1):
            pre = (pre + j) % i
            ndp[j] = cur[pre]
            cur[pre] = (cur[pre] + dp[j]) % mod
        
        dp = ndp
        ans = (ans + dp[n]) % mod
    
    print(ans)