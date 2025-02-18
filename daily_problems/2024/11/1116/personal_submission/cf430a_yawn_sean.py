# Submission link: https://codeforces.com/contest/430/submission/291722279
def main():
    n, m = MII()
    nums = LII()

    st_range = sorted(range(n), key=lambda x: nums[x])
    ans = [0] * n
    for i in range(0, n, 2):
        ans[st_range[i]] = 1

    print(' '.join(map(str, ans)))