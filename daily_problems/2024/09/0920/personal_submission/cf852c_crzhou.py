n = II()
nums =  LII()
tmp = nums[0]
for i in range(n - 1):
    nums[i] += nums[i + 1]
    nums[i] = (nums[i], i)

nums[-1] += tmp
nums[-1] = (nums[-1], n - 1)

nums.sort()
ans = [0] * n
for i in range(n):
    ans[nums[i][1]] = i
print(*ans)
