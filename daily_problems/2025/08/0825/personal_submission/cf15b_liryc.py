'''
https://codeforces.com/problemset/submission/15/335477692
'''
# simple math
def solve(n: int, m: int, x1: int, y1: int, x2: int, y2: int) -> int:
    w, h = n - abs(x1 - x2), m - abs(y1 - y2)
    if w > n // 2 and h > m // 2:
        return n * m - 2 * w * h + (w * 2 - n) * (h * 2 - m)
    else:
        return n * m - 2 * w * h
