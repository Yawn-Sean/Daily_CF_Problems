# Submission link: https://codeforces.com/gym/105833/submission/341145865
def main():
    n = II()
    hs = LII()
    ds = LII()
    cs = LII()
    
    inf = 10 ** 9
    dp = [-inf] * 5001
    
    dp[0] = 0
    
    for i in range(n - 1, -1, -1):
        for j in range(5000, -1, -1):
            nj = fmin(j + ds[i], 5000)
            dp[nj] = fmax(dp[nj], dp[j] - cs[i])
        
        for j in range(5001):
            dp[j] += fmin(j, hs[i])
    
    print(max(dp))