n = ix()
dp = [1] + [0] * n
ans = 0
for i in range(1, n + 1):
    ndp = [0] * (n + 1)
    c = [0] * i
    p = 0
    for j in range(n + 1):
        p = (p + j) % i
        ndp[j] = c[p]
        c[p] = (c[p] + dp[j]) % mod
    dp = ndp
    ans = (ans + dp[-1]) % mod
print(ans)
