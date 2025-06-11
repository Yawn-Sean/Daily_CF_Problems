ef main():
    a, b, x1, y1, x2, y2 = MII()

    def f(x, gridLn):
        l, r = x // gridLn, (x + gridLn - 1) // gridLn
        return l, r

    l1, r1 = f(x1 - y1, 2 * b)
    l2, r2 = f(x2 - y2, 2 * b)
    delta1 = abs(l1 - l2)
    l1, r1 = f(x1 + y1, 2 * a)
    l2, r2 = f(x2 + y2, 2 * a)
    delta2 = abs(l1 - l2)
    return max(delta1, delta2)


T = 1
for ii in range(T):
    print(main())
