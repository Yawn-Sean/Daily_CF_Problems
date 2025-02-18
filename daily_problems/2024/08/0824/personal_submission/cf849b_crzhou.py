n = II()
a = LII()

if a[2] - a[1] == a[1] - a[0]:
    k = a[2] - a[1]
    pre = 0
    for i in range(3, n):
        if a[i] != a[0] + k * i:
            if not pre:
                pre = i
            else:
                if a[i] - a[pre] != k * (i - pre):
                    print('No')
                    exit()
                else:
                    pre = i
    if pre:
        print('Yes')
    else:
        print('No')

else:
    for j, i in (0, 1), (0, 2), (1, 2):
        k = ((a[i] - a[j]) * 2) // (i - j)
        tmp = 3 - i - j
        ca = True
        for x in range(3, n):
            if k * (x - j) != (a[x] - a[j]) * 2 and k * (x - tmp) != (a[x] - a[tmp]) * 2:
                ca = False
                break
        if ca:
            print('Yes')
            exit()
    print('No')
