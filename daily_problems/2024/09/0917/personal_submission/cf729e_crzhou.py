n, boss = MII()
boss -= 1
nums = LII()
ans = 0
if nums[boss] != 0:
    ans += 1
    nums[boss] = 0
nums.sort()
idx = 1
while idx < n and nums[idx] == 0:
    idx += 1
    ans += 1
idx -= 1

tmp = [0] * n
for i in range(idx, n):
    tmp[nums[i]] += 1

mx = max(nums)
wu = 0
for i in range(1, mx + 1):
    if tmp[i] == 0:
        wu += 1

if wu <= idx:
    print(ans)
else:
    l = 1
    while idx > 0:
        if tmp[l] == 0:
            idx -= 1
        l += 1
    r = mx
    while r > l:
        cur = tmp[r]
        while r > l and cur > 0:
            if tmp[l] == 0:
                cur -= 1
                ans += 1
            l += 1
        r -= 1
    print(ans)
