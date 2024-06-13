# Submission link: https://codeforces.com/contest/958/submission/265552835
def main():
    n, k, p = MII()
    nums = [x % p for x in MII()]
    
    acc = list(accumulate(nums, initial=0))
    
    dp = [0] * k
    idx = [0] * k
    
    for i in range(1, n):
        for j in range(k - 1, 0, -1):
            if dp[j-1] + (acc[i] - acc[idx[j-1]]) % p > dp[j]:
                dp[j] = dp[j-1] + (acc[i] - acc[idx[j-1]]) % p
                idx[j] = i
    
    print(dp[k-1] + (acc[-1] - acc[idx[k-1]]) % p)