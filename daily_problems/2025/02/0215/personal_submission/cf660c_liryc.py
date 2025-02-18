'''
https://codeforces.com/problemset/submission/660/306228854
'''
# 滑动窗口带方案输出
def solve(n: int, k: int, a: list[int]):
    i, maxn, l, r = 0, 0, 0, 0
    for j, x in enumerate(a):
        if x == 0:
            k -= 1
            while k < 0:
                if a[i] == 0:
                    k += 1
                i += 1
        if j - i + 1 > maxn:
            maxn, l, r = j - i + 1, i, j
    if maxn:
        a[l:r + 1] = repeat(1, maxn)
    return maxn, a
