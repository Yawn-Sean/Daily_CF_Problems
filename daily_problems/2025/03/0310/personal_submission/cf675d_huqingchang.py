def main():
    n = II()
    res = LII()
    sortedRes = sorted(res)
    d = {v: i for i, v in enumerate(sortedRes)}
    layer = [0] * n
    arr = [-inf, d[res[0]], inf]
    outs = []
    for i in range(1, n):
        x = res[i]
        idx = bisect.bisect_left(arr, d[x])
        l, r = arr[idx - 1], arr[idx]
        if l == -inf:
            outs.append(sortedRes[r])
            layer[d[x]] = layer[r] + 1
        elif r == inf:
            outs.append(sortedRes[l])
            layer[d[x]] = layer[l] + 1
        else:
            if layer[l] > layer[r]:
                outs.append(sortedRes[l])
                layer[d[x]] = layer[l] + 1
            else:
                outs.append(sortedRes[r])
                layer[d[x]] = layer[r] + 1
        bisect.insort(arr, d[x])
    print(*outs)


T = 1
for ii in range(T):
    # print(main())
    # print(ii)
    main()
