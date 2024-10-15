# Submission link: https://codeforces.com/contest/895/submission/282977928
def main():
    n, x, k = MII()
    nums = LII()

    ans = 0

    nums.sort()
    for i in range(n):
        l = (nums[i] - 1) // x + k
        ans += bisect.bisect_left(nums, (l + 1) * x) - bisect.bisect_left(nums, max(nums[i], l * x))

    print(ans)