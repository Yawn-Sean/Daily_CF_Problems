# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n = I()
nums = LI()
one = [0] * (n + 1)
two = [0] * (n + 1)
for i in range(n):
    if nums[i] == 1:
        one[i + 1] = one[i] + 1
        two[i + 1] = two[i]
    elif nums[i] == 2:
        one[i + 1] = one[i]
        two[i + 1] = two[i] + 1

dp = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    dp[i][i] = 1

for k in range(1, n):
    for i in range(n - k):
        dp[i][i + k] = max(dp[i][i + k - 1] + int(nums[i + k] == 1), dp[i + 1][i + k] + int(nums[i] == 2))

# for i in range(n):
#     print(*dp[i])

# print(dp[2][6])

ans = 0
for i in range(n):
    for j in range(i, n):
        left = one[i]
        right = two[n] - two[j + 1]
        ans = max(ans, dp[i][j] + left + right)

print(ans)
