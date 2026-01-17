'''
https://codeforces.com/gym/104149/submission/358249149
'''
def solve(a: float, b: float) -> float:
    c = 4 * b * b * sin(pi / 4)
    if a >= c: 
        return c
    else:
        d = asin(a / 4 / b / b) / 2
        e = b * sin(d)
        return e * e / tan(pi / 8) * 8
