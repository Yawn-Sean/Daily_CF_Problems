'''
https://codeforces.com/problemset/submission/203/334789590
'''
# 计算几何
def solve(a: int, b: int, m: int, vx: int, vy: int, vz: int) -> list[float]:
    t = m / -vy
    h = vz * t % (2 * b)
    z0 = h if h <= b else 2 * b - h
    w = (a / 2 + t * vx) % (2 * a)
    x0 = w if w < a else 2 * a - w
    return [x0, z0]
