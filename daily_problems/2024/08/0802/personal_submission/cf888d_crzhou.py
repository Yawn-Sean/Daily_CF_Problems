from math import comb


n, k = map(int, input().split())
dp = [0, 1, 2, 9]
ans = 1
for i in range(2, k + 1):
    ans += comb(n, n - i) * dp[i - 1]
print(ans)
