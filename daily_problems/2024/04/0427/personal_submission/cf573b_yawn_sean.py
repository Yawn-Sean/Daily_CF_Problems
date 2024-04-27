# Submission link: https://codeforces.com/contest/573/submission/258302490
def main():
    n = II()
    nums = LII()

    nums[0] = nums[-1] = 1
    for i in range(1, n):
        nums[i] = min(nums[i], nums[i-1] + 1)

    for i in range(n - 1, 0, -1):
        nums[i-1] = min(nums[i-1], nums[i] + 1)

    print(max(nums))