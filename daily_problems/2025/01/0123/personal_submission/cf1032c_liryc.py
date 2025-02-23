'''
https://codeforces.com/problemset/submission/1032/302627128
'''
# DP 连方案输出

def solve(n: int, a: list[int]):
    dp = [[0] * 5 for _ in range(n)]
    dp[0][:] = (1, 1, 1, 1, 1)
    for i in range(1, n):
        for j in range(5):
            if a[i] > a[i - 1]:
                for k in range(j):
                    if dp[i - 1][k]:
                        dp[i][j] = k + 1
                        break
            elif a[i] < a[i - 1]:
                for k in range(j + 1, 5):
                    if dp[i - 1][k]:
                        dp[i][j] = k + 1
                        break
            else: # a[i] == a[i - 1]
                for k in range(5):
                    if k != j and dp[i - 1][k]:
                        dp[i][j] = k + 1
                        break
    for k in range(5):
        if dp[-1][k]:
            ans = [0] * n
            for i in range(n - 1, -1, -1):
                ans[i] = k + 1
                k = dp[i][k] - 1
            return ans
    return []

