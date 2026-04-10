n, m = map(int, input().split())

a = []
for i in range(n):
    w, v = map(int, input().split())
    a.append((w, v))

a.sort(key = lambda x: x[1], reverse = True)

ans = 0
for skip in range(min(101, n)):
    dp = [0] * (m + 1)
    for i in range(n):
        if i == skip: continue
        w, v = a[i]
        for j in range(m, w - 1, -1):
            dp[j] = max(dp[j], dp[j - w] + v)
    ans = max(ans, dp[m] + a[skip][1])

print(ans)
