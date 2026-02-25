'''
https://codeforces.com/gym/103870/submission/364214132
'''
# simple math
def solve(a: int, b: int, m: int) -> int:
    d = 1 << m.bit_length() - 1
    v = d - 1
    def calc(n):
        nonlocal d, v
        if n < v:
            return 0
        return (n - v) // d + 1
    return calc(b) - calc(a - 1)
