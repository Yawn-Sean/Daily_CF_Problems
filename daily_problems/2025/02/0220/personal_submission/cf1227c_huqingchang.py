def main():
    n, k = MII()
    s = I()
    lis = []
    for ch in s:
        if ch == '(':
            lis.append(1)
        else:
            lis.append(-1)
    outs = []
    start = 0
    for _ in range(k - 1):
        idx = -1
        for i in range(start, n):
            if lis[i] == 1:
                idx = i
                break
        if idx != start:
            outs.append([start, idx])
            lis[start: idx + 1] = lis[start: idx + 1][::-1]

        idx = -1
        for i in range(start + 1, n):
            if lis[i] == -1:
                idx = i
                break
        if idx != start + 1:
            outs.append([start + 1, idx])
            lis[start + 1: idx + 1] = lis[start + 1: idx + 1][::-1]
        start += 2
    for _ in range(n // 2 - k + 1):
        idx = -1
        for i in range(start, n):
            if lis[i] == 1:
                idx = i
                break
        if idx != start:
            outs.append([start, idx])
            lis[start: idx + 1] = lis[start: idx + 1][::-1]
        start += 1
    print(len(outs))
    for a, b in outs:
        print(a + 1, b + 1)


T = II()
for ii in range(T):
    # print(main())
    # print(ii + 1)
    main()
