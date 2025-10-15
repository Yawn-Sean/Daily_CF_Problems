# Submission link: https://codeforces.com/contest/261/submission/320446673
def main():
    f = [1.0] * 51

    for i in range(1, 51):
        f[i] = f[i - 1] * i

    n = II()
    nums = LII()
    p = II()

    if sum(nums) <= p: print(n)
    else:
        ans = 0
        
        for i in range(n):
            dp = [[0] * (p + 1) for _ in range(n + 1)]
            dp[0][0] = 1
            
            for j in range(n):
                if i == j: continue
                
                for x in range(n, 0, -1):
                    for y in range(p, nums[j] - 1, -1):
                        dp[x][y] += dp[x - 1][y - nums[j]]
        
            for j in range(n + 1):
                for v in range(fmax(0, p - nums[i] + 1), p + 1):
                    ans += dp[j][v] * f[j] * f[n - 1 - j] * j
        
        print(ans / f[n])