def main():
    n = II()
    ps = LII()
    ps = [x // 100 for x in ps]
    x, a = MII()
    y, b = MII()
    k = II()
    ps.sort(reverse=True)
    lc = math.lcm(a, b)

    def check(ln):
        ans = 0
        mxCnt = ln // lc
        aCnt = ln // a - mxCnt
        bCnt = ln // b - mxCnt
        for i in range(mxCnt):
            ans += (x + y) * ps[i]
        if x >= y:
            for i in range(mxCnt, mxCnt + aCnt):
                ans += x * ps[i]
            for i in range(mxCnt + aCnt, mxCnt + aCnt + bCnt):
                ans += y * ps[i]
        else:
            for i in range(mxCnt, mxCnt + bCnt):
                ans += y * ps[i]
            for i in range(mxCnt + bCnt, mxCnt + aCnt + bCnt):
                ans += x * ps[i]
        return ans >= k

    if not check(n):
        return -1
    low, high = 1, n
    ret = n
    while low <= high:
        mid = (low + high) >> 1
        if check(mid):
            ret = mid
            high = mid - 1
        else:
            low = mid + 1
    return ret


T = II()
for ii in range(T):
    print(main())
