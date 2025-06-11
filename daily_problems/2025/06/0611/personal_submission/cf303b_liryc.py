'''
https://codeforces.com/problemset/submission/303/323863044
'''
def solve(n: int, m: int, x: int, y: int, a: int, b: int) -> list[int]:
    g = gcd(a, b)
    a //= g
    b //= g

    t = min(n // a, m // b)
    width, height = t * a, t * b

    x0 = min(n - width, max(x - (width + 1 >> 1), 0))
    y0 = min(m - height, max(y - (height + 1 >> 1), 0))

    return [x0, y0, x0 + width, y0 + height]
