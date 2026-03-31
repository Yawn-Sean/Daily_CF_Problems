n = int(input())

a = [(0, 0)]
for _ in range(n):
    a.append(tuple(map(int, input().split())))

a.sort(key = lambda x: x[1])
dp = [0] * (n + 1)

for i in range(1, n + 1):
    for j in range(i):
        if abs(a[i][0] - a[j][0]) <= abs(a[i][1] - a[j][1]):
            dp[i] = max(dp[i], dp[j] + 1)
    dp[i] = dp[i] if dp[i] else -n

print(max(dp))
