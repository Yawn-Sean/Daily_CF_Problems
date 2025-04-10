def main():
    n, x1, x2 = MII()
    res = LII()
    arr = []
    for i in range(n):
        arr.append([res[i], i + 1])
    arr.sort()

    def f(a, b):
        idx2 = -1
        for i in range(n - 1, -1, -1):
            tot = (n - i) * arr[i][0]
            if tot >= b:
                idx2 = i
                break
        if idx2 == -1:
            return False, 0, 0
        idx1 = -1
        for i in range(idx2 - 1, -1, -1):
            tot = (idx2 - i) * arr[i][0]
            if tot >= a:
                idx1 = i
                break
        if idx1 == -1:
            return False, 0, 0
        return True, idx2 - idx1, n - idx2

    flag, k1, k2 = f(x1, x2)
    if flag:
        print('Yes')
        print(k1, k2)
        for i in range(n - k1 - k2, n - k2):
            print(arr[i][1], end=' ')
        print()
        for i in range(n - k2, n):
            print(arr[i][1], end=' ')
        return
    flag, k1, k2 = f(x2, x1)
    if flag:
        print('Yes')
        print(k2, k1)
        for i in range(n - k2, n):
            print(arr[i][1], end=' ')
        print()
        for i in range(n - k1 - k2, n - k2):
            print(arr[i][1], end=' ')
        return
    print('No')


T = 1
for ii in range(T):
    # print(ii)
    # print(main())
    main()
