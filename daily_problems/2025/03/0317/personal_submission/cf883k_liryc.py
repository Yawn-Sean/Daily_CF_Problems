'''
https://codeforces.com/problemset/submission/883/310976836
'''
# 前后缀分解
def solve(n: int, sa: list[int], ga: list[int]) -> list[str]:
    suf = [0] * n
    for i in range(n - 1, -1, -1):
        suf[i] = sa[i] + ga[i]
        if i < n - 1:
            suf[i] = min(suf[i], suf[i + 1] + 1)
            if suf[i] < sa[i]:
                return ["-1"]
    a = [0] * n
    for i in range(n):
        a[i] = min(suf[i], sa[i] + ga[i])
        if i > 0:
            a[i] = min(a[i], a[i - 1] + 1)
        if a[i] < sa[i]:
            return ["-1"]
    ans = ["", ""]
    ans[0] = sum(x - s for x, s in zip(a, sa))
    ans[1] = ' '.join(map(str, a))
    return ans
