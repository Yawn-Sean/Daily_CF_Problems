'''
https://codeforces.com/problemset/submission/1948/335810080
'''
# string, DP
def solve(s: str) -> int:
    n = len(s)
    dp = [[0] * n for _ in range(n)]
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            if s[i] == '?' or s[j] == '?' or s[i] == s[j]:
                dp[i][j] = 1
                if i:
                    dp[i][j] += dp[i - 1][j - 1]
                if dp[i][j] >= j - i:
                    ans = max(ans, j - i << 1)
    return ans
