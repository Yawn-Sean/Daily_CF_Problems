n, m, k = MII()
s, t = I(), I()

a = defaultdict(int)
a[4] = 5

dp = [[0] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        pre = dp[i - 1][j - 1] if i and j else 0
        dp[i][j] = 1 + pre if s[i] == t[j] else 0

f = [[0] * (m + 1) for _ in range(n + 1)]

for _ in range(k):
    new_f = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(n):
        for j in range(m):
            tmp = dp[i][j]
            new_f[i + 1][j + 1] = max(new_f[i + 1][j], new_f[i][j + 1], tmp + f[i + 1 - tmp][j + 1 - tmp])
    f = new_f
    
print(f[-1][-1])
