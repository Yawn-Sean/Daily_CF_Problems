def main():
    n, k = MII()
    res = LII()
    acc = list(accumulate(res, initial=0))
    if acc[-1] == 0 and k == 0:
        print(0)
        print(*res)
        return
    low, high = k, n
    ans = low

    def check(x):
        for i in range(n):
            end = i + x - 1
            if end > n - 1:
                break
            if acc[end + 1] - acc[i] + k >= x:
                return True
        return False

    mid = -1
    while low <= high:
        mid = (low + high) >> 1
        if check(mid):
            ans = mid
            low = mid + 1
        else:
            high = mid - 1
    print(ans)
    for i in range(n):
        end = i + ans - 1
        if acc[end + 1] - acc[i] + k >= ans:
            for j in range(i, i + ans):
                res[j] = 1
            break
    print(*res)


T = 1
for ii in range(T):
    # print(main())
    main()
