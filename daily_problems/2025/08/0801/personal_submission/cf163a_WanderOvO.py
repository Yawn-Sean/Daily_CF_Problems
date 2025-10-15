"""
考虑以 s[i] 结尾的非空子串，和 t 的前 j 个字符中的子序列，有多少相同的，设为 dp[i][j]
- s[i] == t[j], dp[i][j] += 1 + dp[i - 1][j - 1] + dp[i][j - 1]
- s[i] != t[j], dp[i][j] += dp[i][j - 1]
最后求和所有的 dp[i][m]
"""

s = " " + input()
t = " " + input()
n = len(s) - 1
m = len(t) - 1
dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
mod = int(1e9 + 7)
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if s[i] == t[j]:
            dp[i][j] = 1 + dp[i - 1][j - 1] + dp[i][j - 1]
            dp[i][j] %= mod
        else:
            dp[i][j] = dp[i][j - 1]

res = 0
for i in range(1, n + 1):
    res += dp[i][m]
res %= mod
print(res)
