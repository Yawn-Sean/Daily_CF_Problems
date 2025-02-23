def main():
    n, k, M = MII()
    res = LII()
    sumK = sum(res)
    if M >= sumK * n:
        return n * (k + 1)
    ans = 0
    for i in range(M // sumK + 1):
        base = i * (k + 1)
        lis = []
        for _ in range(n - i):
            lis.extend(res)
        lis.sort()
        s = M - sumK * i
        for x in lis:
            if s < x:
                break
            s -= x
            base += 1
        ans = max(base, ans)
    return ans


T = 1
for ii in range(T):
    print(main())
