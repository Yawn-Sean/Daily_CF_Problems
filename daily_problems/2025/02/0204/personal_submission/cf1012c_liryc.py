'''
https://codeforces.com/problemset/submission/1012/304393024
'''

def solve(n: int, a: list[int]) -> list[int]:
    k = (n + 1) // 2
    ans = [-1] * k

    cost = [0] * n

    for i in range(n):
        if i: 
            cost[i] += max(a[i - 1] - a[i] + 1, 0)
        if i < n - 1: 
            cost[i] += max(a[i + 1] - a[i] + 1, 0)

    dp = cost[:]
    pref = [0] * n

    ans[0] = min(dp)

    for i in range(1, k):
        pref[0] = dp[0]
        for j in range(1, n):
            pref[j] = min(pref[j - 1], dp[j])
        
        for j in range(n - 1, 1, -1):
            dp[j] = min(pref[j - 2] + cost[j], dp[j - 2] + cost[j] - max(a[j - 1] - max(a[j], a[j - 2]) + 1, 0))
        
        dp[0] = 2 * 10 ** 9
        dp[1] = 2 * 10 ** 9
        ans[i] = min(dp)

    return ans
