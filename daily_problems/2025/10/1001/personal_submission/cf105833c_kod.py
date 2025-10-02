n = ix()
h = il()
d = il()
c = il()
dp = [0] + [- inf] * 5000
for i in range(n - 1, -1, -1):
    for v in range(5000, -1, -1):
        vv = min(5000, v + d[i])
        dp[vv] = max(dp[vv], dp[v] - c[i])
    for v in range(5001):
        dp[v] += min(h[i], v)
print(max(dp))
