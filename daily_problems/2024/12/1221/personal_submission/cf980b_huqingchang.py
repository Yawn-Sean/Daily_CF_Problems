def main():
    n, k = MII()
    print('YES')
    ans = [['.'] * n for _ in range(4)]
    if k & 1 == 0:
        half = k >> 1
        for i in range(1, 3):
            for j in range(1, half + 1):
                ans[i][j] = '#'
    else:
        mid = n >> 1
        if k > n - 2:
            for j in range(1, n - 1):
                ans[1][j] = '#'
            k -= n - 2
            half = k >> 1
            for j in range(mid - half, mid + half + 1):
                ans[2][j] = '#'
            ans[2][mid] = '.'
        else:
            half = k >> 1
            for j in range(mid - half, mid + half + 1):
                ans[2][j] = '#'
    for r in ans:
        print(''.join(r))


tt = 1
for ii in range(tt):
    # print(main())
    main()
