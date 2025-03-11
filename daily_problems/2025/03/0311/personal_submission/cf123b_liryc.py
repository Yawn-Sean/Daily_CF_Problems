'''
https://codeforces.com/problemset/submission/123/309902948
'''
def solve(a: int, b: int, x1: int, y1: int, x2: int, y2: int) -> int:
    return max(abs((x1 + y1) // (2 * a) - (x2 + y2) // (2 * a)), abs((x1 - y1) // (2 * b) - (x2 - y2) // (2 * b)))
