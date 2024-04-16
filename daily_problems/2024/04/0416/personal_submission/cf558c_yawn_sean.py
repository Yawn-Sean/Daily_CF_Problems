# Submission link: https://codeforces.com/contest/558/submission/256853970
def main():
    n = II()
    nums = LII()

    cnt = [0] * (10 ** 5 + 1)
    for num in nums:
        while num:
            cnt[num] += 1
            num //= 2

    ma = max(cnt)
    for i in range(10 ** 5, 0, -1):
        if cnt[i] == ma:
            prefix = i
            break

    ans = 0

    for i in range(n):
        v = nums[i] // prefix
        while True:
            v, resid = divmod(nums[i], prefix)
            if v & -v != v or nums[i] % prefix:
                nums[i] //= 2
                ans += 1
            else: break
        nums[i] = nums[i].bit_length()

    nums.sort()
    print(ans + sum(abs(num - nums[n // 2]) for num in nums))