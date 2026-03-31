n = int(input())
a = sorted([tuple(map(int, input().split())) for _ in range(n)], key=lambda x: x[1])
dp = [0] * n
for i in range(n):
    x, y = a[i]
    res = int(x <= y)
    for j in range(i):
        if dp[j] and abs(x - a[j][0]) <= y - a[j][1]:
            res = max(res, dp[j] + 1)
    dp[i] = res
print(max(dp))
