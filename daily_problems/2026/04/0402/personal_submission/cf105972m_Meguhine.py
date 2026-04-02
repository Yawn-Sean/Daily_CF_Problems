"""
以 i 为左端点的逆序对，至少是 max(p[i]-i,0)
因为最坏情况即，[1,i-1] 填 <p[i] 的数
"""
MOD = 10 ** 9 + 7
n, m = map(int, input().split())
dp = [[0] * (m + 1) for _ in range(1 << n)]
dp[0][0] = 1
for s, cur in enumerate(dp):
    for i in range(m + 1):
        cur[i] %= MOD
    p = s.bit_count()
    inv_add = 0
    for i in range(n):
        if s >> i & 1:
            continue
        x = inv_add - max(i - p, 0)
        nw = dp[s | (1 << i)]
        for k in range(m + 1 - x):
            nw[k + x] += cur[k]
        inv_add += 1
print(dp[-1][m] % MOD)
