def main():
    a, b = MII()
    c = b << 2
    s = a * c * 2
    if c == 0:
        return 1
    if a == 0:
        return 0.5
    if a == c:
        return 0.75
    if a > c:
        return 1 - (c ** 2 / 2) / s
    return (a ** 2 / 2 + s / 2) / s


tt = II()
for ii in range(tt):
    print(main())
