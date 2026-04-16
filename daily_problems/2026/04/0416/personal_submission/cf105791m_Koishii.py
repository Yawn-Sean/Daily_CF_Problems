n = int(input())
a = [[] for i in range(n)]

if n == 1: exit(print(0))

for i in range(n):
    a[i] = list(map(int, input().split()))

dp = [[10 ** 9] * n for i in range(1 << n)]
dp[1][0] = 0

for i in range(1, 1 << n):
    for j in range(n):
        if not (i >> j & 1): continue
        for k in range(n):
            if not (i >> k & 1): continue
            dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + a[k][j])

print(min(dp[(1 << n) - 1][i] + a[i][0] for i in range(n)))
