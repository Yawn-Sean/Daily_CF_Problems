'''
https://codeforces.com/problemset/submission/382/304528393
'''
def solve(a: int, b: int, w: int, x: int, c: int) -> int:
    return 0 if c <= a else ((c - a) * w - b + w - x - 1) // (w - x)