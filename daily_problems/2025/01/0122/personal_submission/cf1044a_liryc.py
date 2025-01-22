'''
https://codeforces.com/problemset/submission/1044/302440310
'''
# 二维有序矩阵搜索问题
def solve(n, m, xa, ya):
    xa.sort()
    a = []
    dy = 0
    for x1, x2, y in ya:
        if x1 == 1 and x2 == 1000000000:
            dy += 1
        elif x1 == 1:
            a.append(bisect_right(xa, x2))
    if not a:
        return dy
    a.sort()
    i = 0
    ans = len(a) + dy
    for dx in range(a[-1] + 1):
        while i < len(a) and a[i] <= dx:
            i += 1
        ans = min(ans, len(a) - i + dx + dy)
    return ans