"""
思路： 这局原本想dfs，结果失败了，不知道怎么回事

看了看羊的题解，结合到一个循环里
"""
#python 代码：
n = int(input())
a = list(map(int, input().split()))
b =  list(map(int, input().split()))         
dp = [[0] * (n + 1) for _ in range(2)]
ans = [[0] * (n + 1) for _ in range(2)]
s = [[0] * (n + 1) for _ in range(2)]


for i in range(n - 1, -1, -1):
    s[0][i] = s[0][i + 1] + a[i]
    s[1][i] = s[1][i + 1] + b[i]
    ans[0][i] = ans[0][i + 1] + s[0][i + 1] + s[1][i + 1] + (2 * (n - i) - 1) * b[i]
    ans[1][i] = ans[1][i + 1] + s[0][i + 1] + s[1][i + 1] + (2 * (n - i) - 1) * a[i]
    dp[0][i] = max(ans[0][i], b[i] + dp[1][i + 1] + 2 * (s[1][i + 1] + s[0][i + 1]))
    dp[1][i] = max(ans[1][i], a[i] + dp[0][i + 1] + 2 * (s[1][i + 1] + s[0][i + 1]))

print(dp[0][0])
