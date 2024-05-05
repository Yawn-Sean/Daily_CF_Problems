# -*- coding : utf-8 -*-
# https://codeforces.com/problemset/submission/1575/259589375

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    A = LGMI()

    ck = []
    for i in range(n):
        if A[i] <= i:
            ck.append([A[i], i - A[i]])

    Lst = LazySegmentTree(n + 1, max, 0, max, max, 0)
    ck.sort()
    ans = 0
    last = 0
    i = 0
    while i < len(ck):
        arr = []
        last = ck[i][0]
        while i < len(ck) and ck[i][0] == last:
            arr.append(ck[i][1])
            i += 1
        nup = []
        for j in arr:
            x = Lst.prod(0, j + 1)
            ans = max(ans, x + 1)
            nup.append([j, x + 1])
        for j, k in nup:
            Lst.set(j, k)
    print(ans)
