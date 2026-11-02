# Submission link: https://codeforces.com/gym/106603/submission/397089729
def main(): 
    n = II()
    vals = [0] * (n + 1)
    
    for _ in range(n):
        s, v = MII()
        vals[s] = fmax(vals[s], v)
    
    dp = [0] * (n + 1)
    cur = 0
    
    for i in range(1, n + 1):
        if vals[i] > cur:
            cur = vals[i]
            for j in range(i, n + 1):
                dp[j] = fmax(dp[j], dp[j - i] + vals[i])
    
    print(' '.join(map(str, dp[1:])))