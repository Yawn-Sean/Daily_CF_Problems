'''
https://codeforces.com/gym/106020/submission/380194307
'''
def solve(n: int, k: int) -> int:
    if k.bit_count() >= n:
        return 0
    m = n + 1 >> 1
    w = k - n
    c = 0
    for j in range(30, 1, -1):
        wj = (1 << j) - 1
        mw = m * ((1 << j) - j - 1)
        if w > mw:
            t = w - mw
            cj = (t + wj - 1) // wj
            cj = min(cj, m)
        else:
            cj = 0
        c += cj
        w -= cj * wj
    c1 = w
    c += c1
    c0 = n - c
    return max(0, 2 * c0 - n - 1)