# Submission link: https://codeforces.com/gym/106494/submission/371954301
def main():
    n = II()
    nums = LII()
    nums.sort()
    print(sum(fmax(0, x) for x in nums) + fmin(nums[n // 2], 0))