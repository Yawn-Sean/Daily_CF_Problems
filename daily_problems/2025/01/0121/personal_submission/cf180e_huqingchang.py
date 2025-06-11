def main():
    n, m, k = MII()
    res = LII()

    d = defaultdict(list)
    l, r = 0, 0
    for r in range(1, n):
        if res[r] != res[l]:
            d[res[l]].append([l, r - 1])
            l = r
    d[res[r]].append([l, r])
    ans = 0

    def f(lis):
        ln = len(lis)
        a = 0
        l = 0
        ret = lis[0][1] - lis[0][0] + 1
        for right in range(1, ln):
            a += lis[right][0] - lis[right - 1][1] - 1
            while a > k:
                l += 1
                a -= lis[l][0] - lis[l - 1][1] - 1
            ret = max(ret, lis[right][1] - lis[l][0] + 1 - a)
        return ret

    for ki, v in d.items():
        ans = max(ans, f(v))
    return ans


T = 1
for ii in range(T):
    print(main())
