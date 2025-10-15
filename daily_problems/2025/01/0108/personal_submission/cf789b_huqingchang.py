def main():
    b1, q, l, m = MII()
    res = LII()
    reSet = set(res)

    if b1 == 0:
        if 0 in reSet:
            return 0
        return 'inf'
    if q == 0:
        if abs(b1) > l:
            return 0
        if 0 not in reSet:
            return 'inf'
        if b1 not in reSet:
            return 1
        return 0
    if abs(q) == 1:
        if abs(b1) <= l:
            if b1 not in reSet or b1 * q not in reSet:
                return 'inf'
            return 0
        return 0

    tmp = b1
    ans = 0
    while abs(tmp) <= l:
        if tmp not in reSet:
            ans += 1
        tmp *= q
    return ans


T = 1
for ii in range(T):
    print(main())
