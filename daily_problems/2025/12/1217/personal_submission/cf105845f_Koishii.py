mod = 10 ** 9 + 7

n = int(input())

dp = [0] * (n + 1)
dp[0] = 1

ans = 0

for i in range(1, n + 1):
    ndp = [0] * (n + 1)
    cur = [0] * i
    pre = 0

    for j in range(n + 1):
        pre = (pre + j) % i
        ndp[j] = cur[pre]
        cur[pre] = (cur[pre] + dp[j]) % mod

    dp = ndp
    ans = (ans + dp[n]) % mod
print(ans)
