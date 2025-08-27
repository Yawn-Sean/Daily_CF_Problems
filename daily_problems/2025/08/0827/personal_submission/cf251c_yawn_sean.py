# Submission link: https://codeforces.com/contest/251/submission/335605871
def main():
    a, b, k = MII()
    block = 360360
    inf = 10 ** 6
    
    ans = 0
    
    if a // block != b // block:
        
        dp = [inf] * (block + 1)
        dp[0] = 0
        
        for i in range(1, block + 1):
            dp[i] = fmin(dp[i], dp[i - 1] + 1)
            for j in range(2, k + 1):
                dp[i] = fmin(dp[i], dp[i - i % j] + 1)
        
        ans += dp[a % block]
        a -= a % block
        
        v = (a - b) // block
        ans += dp[block] * v
        a -= v * block
        
        a -= 1
        ans += 1
    
    a %= block
    b %= block
    
    dp = [inf] * block
    dp[b] = 0
    
    for i in range(b + 1, a + 1):
        dp[i] = fmin(dp[i], dp[i - 1] + 1)
        for j in range(2, k + 1):
            dp[i] = fmin(dp[i], dp[i - i % j] + 1)
    
    ans += dp[a]
    print(ans)