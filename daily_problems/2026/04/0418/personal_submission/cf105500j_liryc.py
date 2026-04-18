'''
https://codeforces.com/gym/105500/submission/371629091
dp
'''
def solve(n: int, k: int) -> int:
    MOD = 1000000007
    dp, dp1 = [0] * (n + 1), [0] * (n + 1)
    dp[0] = 1
    
    ans = 0
    for i in range(k + 1):
        y = k - i
        if y > 0:
            for x in range(1, n // y + 1):
                rs = n - y * x
                if rs >= 0:
                    c = (x * x * dp[rs]) % MOD
                    ans = (ans + c) % MOD
        if i < k:
            dp1[0] = 0
            for j in range(1, n + 1):
                dp1[j] = dp[j - 1]
                if j >= (i + 1):
                    dp1[j] = (dp1[j] + dp1[j - i - 1]) % MOD
            dp, dp1 = dp1, dp
    return ans
