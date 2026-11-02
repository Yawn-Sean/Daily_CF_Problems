# Submission link: https://codeforces.com/gym/106788/submission/397093100
def main(): 
    n = II()
    nums = LII()
    
    inf = 100000
    dp = [[inf] * (1 << n) for _ in range(1001)]
    dp[0][0] = 0
    
    for msk in range(1 << n):
        to_add = [j for j in range(n) if msk >> j & 1 == 0]
        
        for j in to_add:
            nmsk = msk | (1 << j)
            
            for k in range(1001):
                if dp[k][msk] < inf:
                    nk = k + nums[j]
                    nv = fmax(nk, dp[k][msk])
                    
                    if nk <= 1000:
                        dp[nk][nmsk] = fmin(dp[nk][nmsk], nv)
                    
                    nk = abs(k - nums[j])
                    nv = fmax(nk, dp[k][msk])
                    
                    dp[nk][nmsk] = fmin(dp[nk][nmsk], nv)
    
    print(min(x[-1] for x in dp))