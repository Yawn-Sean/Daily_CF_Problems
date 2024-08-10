# Submission link: https://codeforces.com/contest/731/submission/275459376
def main():
    n = II()
    nums = LII()

    for i in range(1, n):
        nums[i] += nums[i-1]

    for i in range(n - 2, 0, -1):
        nums[i] = fmax(nums[i+1], nums[i] - nums[i+1])

    print(nums[1])