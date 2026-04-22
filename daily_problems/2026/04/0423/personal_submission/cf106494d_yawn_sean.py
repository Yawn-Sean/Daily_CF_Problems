# Submission link: https://codeforces.com/gym/106494/submission/372105581
def main():
    n = II()
    nums = LII()
    nums.sort()
    
    total = 2 * sum(nums)
    ans = total
    
    for i in range(n):
        total -= 2 * nums[i]
        ans = fmax(ans, total + nums[i // 2] + nums[i - i // 2])
    
    print(ans)