# Submission link: https://codeforces.com/problemset/submission/599/318163061
def main():
    n = II()
    nums = LII()
    tmp = sorted(nums)

    ans = 0
    cur = 0
    for i in range(n):
        cur += tmp[i] - nums[i]
        if cur == 0:
            ans += 1

    print(ans)