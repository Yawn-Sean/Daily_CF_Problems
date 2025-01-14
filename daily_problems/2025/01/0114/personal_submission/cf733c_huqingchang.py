def main():
    n = II()
    A = LII()
    k = I()
    B = LII()
    if sum(A) != sum(B):
        exit(print('NO'))

    lis = []
    idx = 0
    cnt, tmp = 0, []
    for i, j in enumerate(A):
        cnt += j
        if cnt > B[idx]:
            exit(print('NO'))
        tmp.append(j)
        if cnt == B[idx]:
            cnt = 0
            lis.append(tmp)
            tmp = []
            idx += 1
    for r in lis:
        if len(r) > 1 and max(r) == min(r):
            exit(print('NO'))
    print('YES')

    def f(start, L):
        a = L[::]
        while len(a) > 1:
            mx = max(a)
            # modify = set()
            for id, x in enumerate(a):
                if x == mx:
                    if id and x > a[id - 1]:
                        print(start + id + 1, 'L')
                        y = x + a[id - 1]
                        a = a[:id - 1] + [y] + a[id + 1:]
                        break
                    if id < len(a) - 1 and x > a[id + 1]:
                        print(start + id + 1, 'R')
                        y = x + a[id + 1]
                        a = a[:id] + [y] + a[id + 2:]
                        break

    for i, row in enumerate(lis):
        f(i, row)


T = 1
for ii in range(T):
    # print(main())
    main()
