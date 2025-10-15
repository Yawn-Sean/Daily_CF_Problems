# Submission link: https://codeforces.com/contest/768/submission/319315974
def main():
    n, k, x = MII()
    nums = LII()

    dp = [0] * 1024
    ndp = [0] * 1024

    for v in nums:
        dp[v] += 1

    for _ in range(k):
        cur = 0
        
        for i in range(1024):
            a, b = dp[i] - dp[i] // 2, dp[i] // 2
            
            if cur:
                ndp[i ^ x] += b
                ndp[i] += a
            else:
                ndp[i ^ x] += a
                ndp[i] += b
            
            cur ^= dp[i] & 1
        
        for i in range(1024):
            dp[i] = ndp[i]
            ndp[i] = 0

    l, r = -1, -1
    for i in range(1024):
        if dp[i]:
            if l == -1: l = i
            r = i

    print(r, l)