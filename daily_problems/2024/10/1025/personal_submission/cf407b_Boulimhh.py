"""
思路：还是看了🐏的推导公式，推理方面还是得练
"""
#python代码：
m = 10 ** 9 + 7
n = int(input())
p = list(map(int,input().split()))

dp = [0] * (n + 1)
for i in range(1, n + 1):
    dp[i] = (2 * dp[i - 1] + 2 - dp[p[i - 1] - 1])%m

print(dp[-1])
