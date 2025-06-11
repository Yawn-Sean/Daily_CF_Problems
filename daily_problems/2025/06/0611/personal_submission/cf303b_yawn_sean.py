# Submission link: https://codeforces.com/contest/303/submission/323833361
def main():
    n, m, x, y, a, b = MII()
    g = math.gcd(a, b)
    a //= g
    b //= g

    t = fmin(n // a, m // b)
    v, w = t * a, t * b

    x0 = fmin(n - v, fmax(x - (v + 1) // 2, 0))
    y0 = fmin(m - w, fmax(y - (w + 1) // 2, 0))

    print(x0, y0, x0 + v, y0 + w)