# Submission link: https://codeforces.com/contest/613/submission/288651680
def main():
    n, x0, y0 = MII()
    xs = []
    ys = []

    mi1, mi2 = 10 ** 15, 1
    ma = 0

    for _ in range(n):
        x, y = MII()
        x -= x0
        y -= y0
        
        xs.append(x)
        ys.append(y)
        
        v = x * x + y * y
        if v < mi1: mi1 = v
        if v > ma: ma = v

    for i in range(n):
        x1, y1 = xs[i], ys[i]
        x2, y2 = xs[i - 1], ys[i - 1]
        
        v1 = x1 * x1 + y1 * y1
        v2 = x2 * x2 + y2 * y2
        v = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
        
        if v1 + v > v2 and v2 + v > v1:
            a = (x1 * y2 - x2 * y1) ** 2
            b = v
            if a * mi2 < b * mi1:
                mi1 = a
                mi2 = b

    print(math.pi * ((ma * mi2) - mi1) / mi2)