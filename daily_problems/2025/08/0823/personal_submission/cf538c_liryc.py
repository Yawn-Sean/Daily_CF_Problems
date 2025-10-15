'''
https://codeforces.com/contest/538/submission/335105901
'''
# simple math
def solve(n: int, m: int, a: list[list[int]]) -> int:
    d0, h0 = a[0]
    dz, hz = a[-1]
    ans = max(d0 - 1 + h0, n - dz + hz)
    for (d1, h1), (d2, h2) in pairwise(a):
        if abs(h1 - h2) > d2 - d1:
            return -1
        ans = max(ans, h1 + h2 + d2 - d1 >> 1)
    return ans
