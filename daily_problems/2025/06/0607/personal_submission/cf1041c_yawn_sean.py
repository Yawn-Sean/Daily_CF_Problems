# Submission link: https://codeforces.com/contest/1041/submission/323185571
def main():
    n, _, d = MII()
    nums = LII()

    st_range = sorted(range(n), key=lambda x: nums[x])

    l, r = 1, n
    while l <= r:
        m = (l + r) // 2
        flg = True
        
        for i in range(m, n):
            if nums[st_range[i]] - nums[st_range[i - m]] <= d:
                flg = False
        
        if flg: r = m - 1
        else: l = m + 1

    print(l)

    ans = [0] * n
    for i in range(n):
        ans[st_range[i]] = i % l + 1

    print(' '.join(map(str, ans)))