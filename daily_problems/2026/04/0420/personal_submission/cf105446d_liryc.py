'''
https://codeforces.com/gym/105446/submission/371824611
'''
def solve(p: float, r: float, y: float) -> list[float]:
    check = lambda x: max(abs(x), abs(x - r), abs((p + y + r) / 2 - x), abs((y + r - p) / 2 - x))
    lo, hi = -2.0, 2.0
    a = (lo + hi) / 2
    for _ in range(128):
        m1 = (2 * lo + hi) / 3
        m2 = (lo + 2 * hi) / 3
        if check(m1) < check(m2):
            hi = m2
        else:
            lo = m1
        b = (lo + hi) / 2
        diff = abs(a - b)
        a = b
        if diff < 1e-6:
            break
    return [a, (p + y + r) / 2 - a, a - r, (y + r - p) / 2 - a]
