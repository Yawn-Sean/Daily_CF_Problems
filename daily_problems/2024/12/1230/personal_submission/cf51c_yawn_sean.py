# Submission link: https://codeforces.com/contest/51/submission/299017704
def main():
    n = II()
    nums = LII()
    nums.sort()

    def div2(x):
        if x % 2: return f'{x // 2}.500000'
        return f'{x // 2}.000000'

    if n == 1 or n == 2:
        print(div2(0))
        print(div2(nums[0] * 2), div2(nums[-1] * 2), div2(0))
    else:
        l = 0
        r = n - 1
        
        cur = nums[r - 1] - nums[l + 1]
        idx = l + 1
        while l < r:
            if nums[l + 1] - nums[0] < nums[-1] - nums[r - 1]:
                l += 1
            else:
                r -= 1
            v = max(nums[l] - nums[0], nums[-1] - nums[r], nums[r - 1] - nums[l + 1])
            if v < cur: 
                cur = v
                idx = l + 1
        
        print(div2(cur))
        print(div2(nums[0] * 2 + cur), div2(nums[idx] * 2 + cur), div2(nums[-1] * 2 - cur))