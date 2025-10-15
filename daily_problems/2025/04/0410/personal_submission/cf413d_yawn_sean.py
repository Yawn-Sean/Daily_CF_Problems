# Submission link: https://codeforces.com/contest/413/submission/314818676
def main():
    n, k = MII()
    nums = LII()

    total = 1 << k - 1
    dp = [0] * total
    dp[0] = 1

    ndp = [0] * total

    ans = 0
    mod = 10 ** 9 + 7

    for v in nums:
        v //= 2
        
        if v == 0:
            ans += ans
            if ans >= mod:
                ans -= mod
        
        if v != 2:
            for i in range(total - 1):
                ndp[i + 1] += dp[i]
                if ndp[i + 1] >= mod:
                    ndp[i + 1] -= mod
            
            ans += dp[-1]
            if ans >= mod:
                ans -= mod
        
        if v != 1:
            for i in range(1, total, 2):
                ndp[2] += dp[i]
                if ndp[2] >= mod:
                    ndp[2] -= mod
            
            for i in range(0, total - 2, 2):
                ndp[i + 2] += dp[i]
                if ndp[i + 2] >= mod:
                    ndp[i + 2] -= mod
            
            ans += dp[-2]
            if ans >= mod:
                ans -= mod
        
        for i in range(total):
            dp[i] = ndp[i]
            ndp[i] = 0

    print(ans)