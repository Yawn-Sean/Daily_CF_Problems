# Submission link: https://codeforces.com/contest/924/submission/304486902
def main():
    n = II()
    nums = LII()

    up = sum(nums)
    for i in range(n - 2, -1, -1):
        nums[i] = fmax(nums[i + 1] - 1, nums[i])

    for i in range(1, n):
        nums[i] = fmax(nums[i - 1], nums[i])

    print(sum(nums) - up)