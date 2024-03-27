# @TIME
def solve(testcase):
    n, k = MI()
    nums = LII()
    res = 0
    idx = 0
    
    for i in range(n):
        while idx < n and nums[idx] - nums[i] <= k:
            idx += 1
        
        if idx - i >= 3:
            res = max(res, (nums[idx - 1] - nums[i + 1]) / (nums[idx - 1] - nums[i]))

    print(res if res else -1)

for testcase in range(1):
    solve(testcase)
