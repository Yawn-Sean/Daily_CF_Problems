'''
https://codeforces.com/gym/106042/submission/340598859
'''
# 前后缀分解
pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: x if y < 0 or x >= 0 and x <= y else y
def solve(n: int, x: int, y: int, a: list[int]) -> int:
    if n == 1: 
        return (a[0] | x) & y
    suf = [0] * n
    max_suf = [0] * n
    suf[-1] = a[-1]
    max_suf[-1] = a[-1] & y
    for j in range(n - 2, -1, -1):
        suf[j] = a[j] + suf[j + 1]
        max_suf[j] = pmax((a[j] & y) + suf[j + 1], a[j] + max_suf[j + 1])
    ps, max_ps = 0, 0
    ans = -1
    for i in range(n):
        s = 0
        if i == 0:
            s = pmax(((a[i] | x) & y) + suf[i + 1], (a[i] | x) + max_suf[i + 1])
            max_ps = a[i] & y
        elif i == n - 1:
            s = pmax(((a[i] | x) & y) + ps, (a[i] | x) + max_ps)
        else:
            s = pmax(((a[i] | x) & y) + ps + suf[i + 1], (a[i] | x) + pmax(ps + max_suf[i + 1], max_ps + suf[i + 1]))
            max_ps = pmax(ps + (a[i] & y), max_ps + a[i])
        ans = pmin(ans, s)
        ps += a[i]
    return ans
