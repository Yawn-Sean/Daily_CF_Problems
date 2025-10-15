def main():
    k, n = MII()
    res = LII()
    distinct = LII()

    acc = list(accumulate(res))
    tot = set(distinct)
    ans, fir = 0, distinct[0]

    def f(i):
        candi = set()
        for j in range(k):
            tmp = fir - acc[i] + acc[j]
            candi.add(tmp)
        for x in distinct:
            if x not in candi:
                return False, 0
        return True, fir - acc[i] + acc[0]

    ansSet = set()
    for idx in range(k):
        flag, ans = f(idx)
        if flag:
            ansSet.add(ans)
    return len(ansSet)


T = 1
for ii in range(T):
    print(main())
