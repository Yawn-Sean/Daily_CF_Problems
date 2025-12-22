'''
https://codeforces.com/gym/105761/submission/354580361
'''
# binary search (WA)
def solve(n: int, p: int) -> int:
    def getp(x):
        nonlocal n, p
        if x <= 1:
            return 99999 # > maximum(p)
        elif x == n:
            return 1
        m, r = n, 1
        while m > x:
            r += 1
            m = (m + x - 1) // x
        return r
    def getw(x):
        nonlocal n, p
        if x == n:
            return n - 1
        m, w = n, 0
        while m > x:
            w += x - 1
            m = (m + x - 1) // x
        return w + m - 1
    min_x = bisect_left(range(n + 1), True, key=lambda x: getp(x) <= p)
    return getw(min_x)
