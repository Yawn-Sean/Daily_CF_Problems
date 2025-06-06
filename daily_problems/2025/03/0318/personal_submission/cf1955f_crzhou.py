t = II()
for _ in range(t):
    nums = LII()
    ans = nums[3] // 2
    ans += max(min(nums[0], nums[1], nums[2]), \
               nums[0] // 2 + nums[1] // 2 + nums[2] // 2 + (1 if nums[0] % 2 and nums[1] % 2 and nums[2] % 2 else 0)) 
    print(ans)
