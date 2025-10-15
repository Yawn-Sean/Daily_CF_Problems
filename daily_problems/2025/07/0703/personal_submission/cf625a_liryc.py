'''
https://codeforces.com/problemset/submission/625/327204621
'''
def solve(n: int, a: int, b: int, c: int) -> int:
    if n >= b and b - c <= a:
        d = (n - b) // (b - c) + 1
        return d + (n - d * (b - c)) // a
    else:
        return n // a