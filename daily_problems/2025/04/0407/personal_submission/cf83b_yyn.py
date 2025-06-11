def yyn():
    n,k = MII()
    a = LII()
    if sum(a) < k:
        return print(-1)

    def check(mx):
        cnt = 0
        for x in a:
            cnt += min(mx,x)
        return cnt >= k

    l,r = -1,10 ** 12
    while l + 1 < r:
        mid = (l + r) >> 1
        if check(mid):
            r = mid
        else:
            l = mid

    suf = [0] * (n + 1)
    for i in range(n - 1,-1,-1):
        suf[i] = suf[i + 1] + min(a[i],r - 1)

    s = 0
    for i in range(n + 1):
        if s + suf[i] == k:
            ans = []
            for j in range(i,n):
                if a[j] - r + 1 > 0:
                    ans.append(j + 1)
            for j in range(i):
                if a[j] - r > 0:
                    ans.append(j + 1)
            return print(*ans)
        s += min(a[i],r)


