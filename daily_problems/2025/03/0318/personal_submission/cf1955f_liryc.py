'''
https://codeforces.com/problemset/submission/1955/311234662
'''
def solve(a: int, b: int, c: int, d: int) -> int:
    return a // 2 + b // 2 + c // 2 + d // 2 + (a & b & c & 1)
