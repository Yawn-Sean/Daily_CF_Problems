# Submission link: https://codeforces.com/contest/245/submission/318679628
def main():
    n = II()
    nums = LII()

    if n % 2 == 0 or n == 1: print(-1)
    else:
        ans = 0
        for i in range(n - 1, -1, -1):
            if 2 * i + 2 < n:
                v = fmax(nums[2 * i + 1], nums[2 * i + 2])
                nums[i] = fmax(0, nums[i] - v)
                ans += v
        print(ans + nums[0])