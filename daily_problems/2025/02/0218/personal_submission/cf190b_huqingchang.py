def main():
    x1, y1, r1 = MII()
    x2, y2, r2 = MII()
    d2 = (x1 - x2) ** 2 + (y1 - y2) ** 2
    if r1 < r2:
        r1, r2 = r2, r1
    if d2 < r1 ** 2 + r2 ** 2 - 2 * r1 * r2:
        return (r1 - r2 - d2 ** 0.5) / 2
    # if d2 == r1 ** 2 + r2 ** 2 - 2 * r1 * r2:
    #     return 0
    if d2 <= r1 ** 2 + r2 ** 2 + 2 * r1 * r2:
        return 0
    if d2 > r1 ** 2 + r2 ** 2 + 2 * r1 * r2:
        return (d2 ** 0.5 - r1 - r2) / 2


T = 1
for ii in range(T):
    print(main())
