'''
https://codeforces.com/problemset/submission/255/313225305
'''
# 二分
def solve(n: int, x: int, y: int, c: int) -> int:
    def check(t):
        nonlocal n, x, y
        if t == 0:
            return 0
        a = [x, y, n - x + 1, n - y + 1]

        def area(s, r1, r2):
            nonlocal n
            if r1 + r2 <= s:
                return r1 * r2
            else:
                res = (s + 1) * s >> 1
                d1, d2 = s - r1, s - r2
                if d1 > 0:
                    res -= (d1 + 1) * d1 >> 1
                if d2 > 0:
                    res -= (d2 + 1) * d2 >> 1
                return res
            
        return sum(area(t, r1, r2) for r1, r2 in pairwise(a + [a[0]])) - sum(min(t, x) for x in a) + 1
    return bisect_left(range(n * 2), c, key = check) - 1
