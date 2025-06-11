# Submission link: https://codeforces.com/contest/1012/submission/304335826
def main():
    n = II()
    nums = LII()

    k = (n + 1) // 2
    ans = [-1] * k

    inf = 10 ** 9

    cost = [0] * n

    for i in range(n):
        if i: cost[i] += fmax(nums[i - 1] - nums[i] + 1, 0)
        if i < n - 1: cost[i] += fmax(nums[i + 1] - nums[i] + 1, 0)

    dp = cost[:]
    pref = [0] * n

    ans[0] = min(dp)

    for i in range(1, k):
        pref[0] = dp[0]
        for j in range(1, n):
            pref[j] = fmin(pref[j - 1], dp[j])
        
        for j in range(n - 1, 1, -1):
            dp[j] = fmin(pref[j - 2] + cost[j], dp[j - 2] + cost[j] - fmax(nums[j - 1] - fmax(nums[j], nums[j - 2]) + 1, 0))
        
        dp[0] = inf
        dp[1] = inf
        ans[i] = min(dp)

    print(' '.join(map(str, ans)))