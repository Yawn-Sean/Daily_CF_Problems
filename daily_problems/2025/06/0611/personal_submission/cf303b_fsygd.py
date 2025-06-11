import math

def solve(n, x, l):
    if x - (l + 1) // 2 >= 0 and x + l // 2 <= n:
        return x - (l + 1) // 2, x + l // 2
    if x - l // 2 >= 0 and x + (l + 1) // 2 <= n:
        return x - l // 2, x + (l + 1) // 2
    # (0, l) vs (n - l, n)
    if abs((n - l + n) / 2 - x) < abs(l / 2 - x):
        return n - l, n
    else:
        return 0, l

if __name__ == '__main__':
    n, m, x, y, a, b = list(map(int, input().split(' ')))
    a, b = a // math.gcd(a, b), b // math.gcd(a, b)
    a, b = a * min(n // a, m // b), b * min(n // a, m // b)
    x1, x2 = solve(n, x, a)
    y1, y2 = solve(m, y, b)
    print(x1, y1, x2, y2)