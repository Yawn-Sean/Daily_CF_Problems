'''
https://codeforces.com/gym/106188/submission/348840442
'''
# DP
def solve(n: int, k: int, a: list[int]) -> int:
    MOD = 1000000007
    a.sort()
    ans = 0
    dp = [[0] * 10002 for _ in range(k)]
    dp[0][0] = 1
    for i, x in enumerate(a):
        ans = (ans + sum(dp[k - 1][x + 1:])) % MOD
        for j in range(k - 1, 0, -1):
            for c in range(10002):
                if dp[j - 1][c]:
                    d = pmin(10001, c + x)
                    e = dp[j - 1][c]
                    dp[j][d] = (dp[j][d] + e) % MOD
    return ans
