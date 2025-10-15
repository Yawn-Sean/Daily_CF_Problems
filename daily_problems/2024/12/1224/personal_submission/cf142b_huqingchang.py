def main():
    m, n = MII()
    if min(m, n) == 1:
        return m * n
    if min(m, n) == 2:
        a = max(m, n)
        b, c = divmod(a, 4)
        return b * 4 + min(2 * c, 4)
    mn = m * n
    return (mn + 1) // 2


tt = 1
for ii in range(tt):
    print(main())
