def solve():
    n, k = MII()
    res = 0
    d = [0] * (k + 1)
    d[1] = 0
    if k >= 2:
        d[2] = 1
    for i in range(3, k + 1):
        d[i] = (i - 1) * (d[i - 1] + d[i - 2])
    def cul(n, m):
        res, button = 1, 1
        for i in range(1, m + 1):
            button *= i
            res *= n
            n -= 1
        return res // button
    for i in range(n - k, n + 1):
        res += cul(n, n - i) * d[n - i]
    print(res + 1)


def main():
    t = 1
    while t:
        solve()
        t -= 1
main()
