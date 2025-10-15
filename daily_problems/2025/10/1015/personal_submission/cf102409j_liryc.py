'''
https://codeforces.com/gym/102409/submission/343826649
'''
# 枚举分割点
pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: y if y < x else x
def solve(n: int, l: int, xa: list[int]) -> int:
    a = [0] * n
    for i, x in enumerate(xa):
        a[i] = x if i == 0 else x - xa[i - 1]
    a[-1] = l - xa[-1]
    def calc():
        nonlocal a
        a_lo, a_hi = [0] * n, [0] * n
        i, sl, sr = 0, a[0], 0
        for j in range(1, n):
            sr += a[j]
            d = abs(sr - sl)
            sl_next, sr_next = sl + a[i + 1], sr - a[i + 1]
            d_next = abs(sl_next - sr_next)
            while d_next < d:
                sl, sr, d = sl_next, sr_next, d_next
                i += 1
                sl_next, sr_next = sl + a[i + 1], sr - a[i + 1]
                d_next = abs(sl_next - sr_next)
            a_lo[j], a_hi[j] = pmin(sl, sr), pmax(sl, sr)
        return a_lo, a_hi
    pre_lo, pre_hi = calc()
    a.reverse()
    suf_lo, suf_hi = calc()
    suf_lo.reverse()
    suf_hi.reverse()

    # enumerate the middle cut
    ans = l
    for i in range(1, n - 2):
        left_lo, left_hi, right_lo, right_hi = pre_lo[i], pre_hi[i], suf_lo[i + 1], suf_hi[i + 1]
        ans = pmin(ans, pmax(left_hi, right_hi) - pmin(left_lo, right_lo))
    
    return ans
