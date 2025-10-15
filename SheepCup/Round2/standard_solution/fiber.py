def main():
    n, r, h, x0, y0, vx, vy = MII()
    a = vx * vx + vy * vy
    b = 2 * vx * x0 + 2 * vy * y0
    c = x0 * x0 + y0 * y0 - r * r
    delta = b * b - 4 * a * c
    t1 = (-b + delta ** 0.5) / 2 / a
    t2 = delta ** 0.5 / a
    print(h / (t1 + n * t2), h / (t1 + (n - 1) * t2))