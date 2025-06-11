n = II()
nums = LII()

bac = [[0, 0] for _ in range(n)]
pre = nums[-1]
for i in range(n - 2, -1, -1):
    bac[i][0] = bac[i + 1][0] + pre - nums[i + 1]
    cur = fmax(nums[i], pre + 1)
    bac[i][1] = cur
    pre = cur

ans = bac[0][0] + fmax(bac[0][1], nums[0]) - nums[0]
pre = nums[0]
tmp = 0
for i in range(1, n):
    tmp += pre - nums[i - 1]
    cur = fmax(nums[i], pre + 1)
    pre = cur
    ans = fmin(ans, bac[i][0] + tmp + fmax(bac[i][1], cur) - nums[i])

print(ans)
