# Submission link: https://codeforces.com/contest/671/submission/295957821
def main():
    n, k = MII()
    nums = LII()

    ans = 0

    l, r = min(nums), sum(nums) // n

    while l <= r:
        m = (l + r) // 2
        cur = 0
        for i in range(n):
            cur += fmax(0, m - nums[i])
            if cur > k: break
        if cur > k: r = m - 1
        else: l = m + 1

    ans -= r

    l, r = (sum(nums) + n - 1) // n, max(nums)

    while l <= r:
        m = (l + r) // 2
        cur = 0
        for i in range(n):
            cur += fmax(0, nums[i] - m)
            if cur > k: break
        if cur > k: l = m + 1
        else: r = m - 1

    ans += l

    print(ans)