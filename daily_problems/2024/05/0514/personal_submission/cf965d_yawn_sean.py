# Submission link: https://codeforces.com/contest/965/submission/260864277
def main():
    n, l = MII()
    nums = LII()

    cur = sum(nums[:l])
    ans = cur

    for i in range(n - 1 - l):
        cur -= nums[i]
        cur += nums[i + l]
        ans = min(ans, cur)

    print(ans)