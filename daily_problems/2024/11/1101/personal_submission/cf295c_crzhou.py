n, k = MII()
k //= 50
nums = LII()

a = b = 0
for x in nums:
    if x == 50:
        a += 1
    else:
        b += 1

# dp1[i][j]: 左边（源）有 i 个 1，j 个 2 的方案数，dp2[i][j]: 右边（目的地）有 i 个 1，j 个 2 的方案数
dp1 = [[0] * (b + 1) for _ in range(a + 1)]
dp1[-1][-1] = 1
dp2 = [[0] * (b + 1) for _ in range(a + 1)]
dp2[0][0] = 1

cnt = 0
for cnt in range(4 * n + 1):
    for i in range(a + 1):
        for j in range(b + 1):
            for di in range(i + 1):
                for dj in range(j + 1):
                    if cnt % 2 == 0:
                        if (di or dj) and a - (i - di) >= di and b - (j - dj) >= dj and di + dj * 2 <= k:
                            dp2[i][j] = (dp2[i][j] + dp1[a - (i - di)][b - (j - dj)] * comb(a - (i - di), di) * comb(b - (j - dj), dj)) % MOD                           
                    else:
                        if (di or dj) and a - (i - di) >= di and b - (j - dj) >= dj and di + dj * 2 <= k:
                            dp1[i][j] = (dp1[i][j] + dp2[a - (i - di)][b - (j - dj)] * comb(a - (i - di), di) * comb(b - (j - dj), dj)) % MOD
    if dp2[a][b]:
        print(cnt + 1)
        print(dp2[a][b])
        exit()

print(-1)
print(0)
