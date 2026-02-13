'''
https://codeforces.com/gym/106363/submission/362773267
2026/2/13 Y1
1600
'''
# prefix and suffix sum
def solve(n: int, a: list[int]) -> list[int]:
    ia = [0] * n
    for i, x in enumerate(a):
        ia[x] = i
    l, r = ia[0], ia[0]
    diff_pre, diff_suf = [0] * n, [0] * n
    for x in range(n):
        i = ia[x]
        l = pmin(l, i)
        r = pmax(r, i)
        diff_pre[r] += l + 1
        diff_suf[l] += n - r
    pres, sufs = [0] * n, [0] * n
    ps = 0
    for i in range(n):
        ps += diff_pre[i]
        pres[i] = ps
        if i:
            pres[i] += pres[i - 1]
    ps = 0
    for i in range(n - 1, -1, -1):
        ps += diff_suf[i]
        sufs[i] = ps
        if i < n - 1:
            sufs[i] += sufs[i + 1]

    ans = [0] * n
    all_sum = pres[-1]
    for i in range(n):
        ans[i] = all_sum
        if i:
            ans[i] -= pres[i - 1]
        if i < n - 1:
            ans[i] -= sufs[i + 1]

    return ans
