def main():
    n = II()
    cnt = [0] * 10
    tot = 0
    for x in LII():
        cnt[x] += 1
        tot += x

    def print_answer():
        ret = ''
        for ki in range(9, -1, -1):
            ret += str(ki) * cnt[ki]
        if ret[0] == '0':
            print(0)
        else:
            print(ret)

    if cnt[0] == 0:
        exit(print(-1))
    if tot % 3 == 0:
        print_answer()
        return
    for i in range(1, 10):
        if cnt[i] and (tot - i) % 3 == 0:
            cnt[i] -= 1
            print_answer()
            return
    for i in range(1, 10):
        if (tot - 2 * i) % 3 == 0 and cnt[i]:
            cnt[i] -= 1
            for j in range(i, 10):
                if (tot - i - j) % 3 == 0 and cnt[j]:
                    cnt[j] -= 1
                    print_answer()
                    return


T = 1
for ii in range(T):
    # print(main())
    # print(ii)
    main()
