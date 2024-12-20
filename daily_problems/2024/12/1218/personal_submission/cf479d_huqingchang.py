def main():
    n, l, x, y = MII()
    res = LII()
    resSet = set(res)
    # ans = 0
    needs = []

    def check(d):
        for ln in res:
            if ln - d in resSet or ln + d in resSet:
                return True
        return False

    flagX, flagY = check(x), check(y)
    if flagX and flagY:
        print(0)
        return
    if not flagX and not flagY:
        candi = [x, y]
        tar = 0
        for ln in res:
            for c in [-1, 1]:
                for i in range(2):
                    tar = ln + c * candi[i]
                    if 0 <= tar <= l and (tar - candi[i ^ 1] in resSet or tar + candi[i ^ 1] in resSet):
                        print(1)
                        print(tar)
                        return
        print(2)
        print(x, y)
        return
    if flagX:
        needs.append(y)
    else:
        needs.append(x)
    print(1)
    print(needs[0])


tt = 1
for ii in range(tt):
    # print(main())
    main()
