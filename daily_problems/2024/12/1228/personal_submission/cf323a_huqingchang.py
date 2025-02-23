def main():
    n = II()
    if n & 1:
        print(-1)
        return
    cur = 0
    for _ in range(n):
        cur ^= 1
        g = [[''] * n for _ in range(n)]
        # tmp = cur
        for i in range(n // 2):
            for j in range(n // 2):
                tmp = cur
                if (i + j) & 1:
                    tmp = cur ^ 1
                color = ''
                if not tmp:
                    color = 'w'
                else:
                    color = 'b'
                for k in range(2 * i, 2 * i + 2):
                    for l in range(2 * j, 2 * j + 2):
                        g[k][l] = color
        for r in g:
            print(''.join(r))
        print()


T = 1
for ii in range(T):
    # print(main())
    main()
