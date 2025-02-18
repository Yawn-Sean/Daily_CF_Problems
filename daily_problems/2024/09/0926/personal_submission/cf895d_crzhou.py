n, x, k = MII()
nums = LII()
nums.sort()
ans = 0

l = r = 0
for i in range(n):
    if nums[i] // x >= k:
        tmp = nums[i] // x
        while r < n and nums[r] <= nums[i] and (nums[r] - 1) // x <= tmp - k:
            r += 1
        while l < n and (nums[l] - 1) // x <= tmp - k - 1:
            l += 1
        ans += r - l
print(ans)
