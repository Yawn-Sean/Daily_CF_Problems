# Submission link: https://codeforces.com/contest/440/submission/321985729
def main():
    n = II()
    nums = LII()

    val = sum(nums) // n

    ans = 0
    cur = 0

    for x in nums:
        cur += x - val
        ans += abs(cur)

    print(ans)