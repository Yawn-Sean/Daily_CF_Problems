# Submission link: https://codeforces.com/contest/257/submission/295814182
def main():
    n = II()
    nums = LII()

    ans = [1] * n
    cur = nums[-1]

    for i in range(n - 2, -1, -1):
        if abs(cur + nums[i]) < abs(cur - nums[i]):
            cur += nums[i]
        else:
            cur -= nums[i]
            ans[i] = 0

    if cur < 0:
        for i in range(n):
            ans[i] ^= 1

    print(''.join('+' if x else '-' for x in ans))