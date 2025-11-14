fmin = lambda x, y: x if x < y else y

n, k = il()
a = sorted(il())
l = 10 ** 4 + 2
dp = [[0] * l for i in range(k)]
dp[0][0] = 1
ans = 0
for i in range(n):
    for j in range(a[i] + 1, l):
        ans += dp[k - 1][j]
        if ans > mod:
            ans -= mod
    for x in range(k - 2, -1, -1):
        for y in range(l):
            ny = fmin(y + a[i], l - 1)
            dp[x + 1][ny] += dp[x][y]
            if dp[x + 1][ny] > mod:
                dp[x + 1][ny] -= mod
print(ans)
