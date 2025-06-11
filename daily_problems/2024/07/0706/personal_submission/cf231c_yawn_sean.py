# Submission Link: https://codeforces.com/contest/231/submission/268996419
def main():
    n, k = MII()
    nums = LII()

    nums.sort()
    l, r = 0, 0
    cur = 0

    ans = 0
    val = 0
    while l < n:
        while r < n and cur + (nums[r] - nums[r - 1]) * (r - l) <= k:
            cur += (nums[r] - nums[r - 1]) * (r - l)
            r += 1
        if r - l > ans:
            ans = r - l
            val = nums[r - 1]
        cur -= nums[r - 1] - nums[l]
        l += 1

    print(ans, val)