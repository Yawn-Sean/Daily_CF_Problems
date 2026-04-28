'''
https://codeforces.com/gym/106500/submission/372775450
'''
def solve(a: int, b: int, c: int, d: int) -> int:
    if a == b:
        if c != d:
            return 0
        m1 = c // (a << 1 | 1)
        k1 = 2 * m1
        if c >= a + 1:
            m2 = (c - a - 1) // (a << 1 | 1)
            k2 = 2 * m2 + 1
        else:
            k2 = -1
        return c - a * max(k1, k2)
    else:
        d1 = c - d
        d2 = a - b
        if d1 % d2 != 0:
            return 0
        k = d1 // d2
        if k < 0:
            return 0
        ans = c - a * k
        if ans < 0 or k + 1 >> 1 > ans:
            return 0
        return ans