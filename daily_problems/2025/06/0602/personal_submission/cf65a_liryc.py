'''
https://codeforces.com/problemset/submission/65/322494859
'''
def solve(a: int, b: int, c: int, d: int, e: int, f: int) -> str:
    return "Ron" if a * c * e < b * d * f or not a and b and d or not c and d else "Hermione"
