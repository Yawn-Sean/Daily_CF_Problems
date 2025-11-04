# Submission link: https://codeforces.com/gym/105934/submission/347365421
def main(): 
    n = II()
    nums = LII()
    
    ans = 10 ** 16
    
    res = 0
    cur = nums[0]
    
    for i in range(1, n):
        if i % 2:
            cur = fmax(cur + 1, nums[i])
            res += cur - nums[i]
        else:
            cur = fmin(cur - 1, nums[i])
            res += nums[i] - cur
    
    ans = fmin(ans, res)
    
    res = 0
    cur = nums[0]
    
    for i in range(1, n):
        if i % 2 == 0:
            cur = fmax(cur + 1, nums[i])
            res += cur - nums[i]
        else:
            cur = fmin(cur - 1, nums[i])
            res += nums[i] - cur
    
    ans = fmin(ans, res)
    
    print(ans)