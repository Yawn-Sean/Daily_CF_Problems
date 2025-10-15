def main():
    n, p = MII()
    res = []
    totCost = 0
    totStore = 0
    for _ in range(n):
        c, s = MII()
        res.append([c, s])
        totCost += c
        totStore += s
    if totCost <= p:
        return -1
    tmp = totCost - p
    low, high = 0, totStore / tmp + 1
    ans = 0

    def check(x):
        need = 0
        for c, s in res:
            need += max(0, c * x - s)
        return need <= x * p

    while low < high - 10 ** -6:
        mid = (low + high) / 2
        if check(mid):
            ans = mid
            low = mid
        else:
            high = mid
    return ans


T = 1
for ii in range(T):
    print(main())
