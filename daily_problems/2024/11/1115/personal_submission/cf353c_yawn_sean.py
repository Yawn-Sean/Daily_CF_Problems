# Submission link: https://codeforces.com/contest/353/submission/291510458
def main():
    n = II()
    nums = LII()
    s = I()

    cur = sum(nums)
    ans = 0

    for i in range(n - 1, -1, -1):
        cur -= nums[i]
        if s[i] == '1':
            ans = fmax(ans, cur)
            cur += nums[i]

    print(fmax(ans, cur))