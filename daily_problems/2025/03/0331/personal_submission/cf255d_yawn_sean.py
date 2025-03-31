# Submission link: https://codeforces.com/problemset/submission/255/313186727
def main():
    n, x, y, c = MII()

    l, r = 0, n * 2

    while l <= r:
        m = (l + r) // 2
        res = 2 * m * m + 2 * m + 1
        if m > x - 1: res -= (m - (x - 1)) * (m - (x - 1))
        if m > n - x: res -= (m - (n - x)) * (m - (n - x))
        if m > y - 1: res -= (m - (y - 1)) * (m - (y - 1))
        if m > n - y: res -= (m - (n - y)) * (m - (n - y))
        
        if m > (x - 1) + (y - 1):
            res += (m - ((x - 1) + (y - 1)) - 1) * (m - ((x - 1) + (y - 1))) // 2
        if m > (x - 1) + (n - y):
            res += (m - ((x - 1) + (n - y)) - 1) * (m - ((x - 1) + (n - y))) // 2
        if m > (n - x) + (y - 1):
            res += (m - ((n - x) + (y - 1)) - 1) * (m - ((n - x) + (y - 1))) // 2
        if m > (n - x) + (n - y):
            res += (m - ((n - x) + (n - y)) - 1) * (m - ((n - x) + (n - y))) // 2
        
        if res >= c: r = m - 1
        else: l = m + 1

    print(l)