def main():
    n, m = MII()
    ver = []
    hor = []

    for _ in range(n):
        x = II()
        ver.append(x)
    for _ in range(m):
        x1, x2, y = MII()
        if x1 == 1:
            hor.append(x2)
    ver.sort()
    ver.append(10 ** 9)
    hor.sort()
    ans = m + n
    for i, x in enumerate(ver):
        ret = i + len(hor) - bisect.bisect_left(hor, x)
        ans = min(ret, ans)
    return ans


T = 1
for ii in range(T):
    print(main())
