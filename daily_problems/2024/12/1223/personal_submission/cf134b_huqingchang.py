def main():
    n = II()
    if n == 1:
        return 0

    ans = inf

    def f(x, y):
        if x == 1:
            return y - 1
        return f(y % x, x) + y // x

    for i in range(1, n):
        if math.gcd(i, n) > 1:
            continue
        ans = min(ans, f(i, n))
    return ans


tt = 1
for ii in range(tt):
    print(main())
