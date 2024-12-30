"""
question: https://codeforces.com/problemset/problem/1498/C
submission: https://codeforces.com/contest/1498/submission/263590600
"""

def main(ac=FastIO()):
    MOD = 10 ** 9 + 7
    ans = []
    for _ in range(ac.read_int()):
        n, m = ac.read_list_ints()
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(n + 1): 
            dp[i][1] = 1 
        for j in range(2, m + 1):
            dp[0][j] = 1 
            for i in range(1, n + 1):
                dp[i][j] = (dp[i - 1][j] + dp[n - i][j - 1]) % MOD
        ans.append(dp[n][m])
    ac.flatten(ans)

main()
