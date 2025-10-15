def yyn():
    n,l,r,c = MII()
    def check(x):
        tot = 2 * x * x + 2 * x + 1
        tot -= max(0,x - l + 1) ** 2
        tot -= max(0,x + l - n) ** 2
        tot -= max(0,x - r + 1) ** 2
        tot -= max(0,x + r - n) ** 2
        tot += max(x - l - r + 1,0) * (max(x - r - l + 1,0) + 1) // 2
        tot += max(x + l - r - n,0) * (max(x - r + l - n,0) + 1) // 2
        tot += max(x - l + r - n,0) * (max(x + r - l - n,0) + 1) // 2
        tot += max(x - 2 * n + r + l - 1,0) * (max(x - 2 * n + r + l - 1,0) + 1) // 2
        return tot >= c

    left = -1
    right = int(1e14)
    while left + 1 < right:
        mid = (left + right) // 2
        if check(mid):
            right = mid
        else:
            left = mid
    print(right)
