'''
https://codeforces.com/problemset/submission/630/305465336
'''
def solve(x1: int, y1: int, x2: int, y2: int) -> int:
    a = x2 - x1 + 1
    b = y2 - y1 + 1
    return (a + 1 >> 1) * (b + 1 >> 1) + (a - 1 >> 1) * (b - 1 >> 1)