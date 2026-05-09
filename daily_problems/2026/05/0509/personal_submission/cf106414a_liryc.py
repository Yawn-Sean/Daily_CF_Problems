'''
https://codeforces.com/gym/106414/submission/373971489
simple Math
'''
def solve(n: int, m: int, r1: int, c1: int, r2: int, c2: int) -> int:
    cf = lambda d: 2 - (d & 1) if d else 0
    return cf(abs(r1 - r2)) + cf(abs(c1 - c2))
