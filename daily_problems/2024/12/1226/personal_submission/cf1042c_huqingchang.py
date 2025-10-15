def main():
    n = II()
    res = [0] + LII()

    if all(res[i] == 0 for i in range(1, n + 1)):
        for i in range(1, n):
            print(1, i, i + 1)
        return
    if 0 in res[1:]:
        ans = 1
        zeros = []
        pos = []
        neg = []
        for i in range(1, n + 1):
            if res[i] > 0:
                pos.append(i)
            elif res[i] == 0:
                zeros.append(i)
            else:
                neg.append(i)
                ans = -ans
        if ans > 0:
            for a, b in pairwise(zeros):
                print(1, a, b)
            print(2, zeros[-1])
            for a, b in pairwise(pos + neg):
                print(1, a, b)
        else:
            if len(pos) + len(neg) == 1:
                print(2, neg[0])
                for a, b in pairwise(zeros):
                    print(1, a, b)
            else:
                mi = min(abs(res[i]) for i in neg)
                miIdx = -1
                for i in neg:
                    if res[i] == -mi:
                        miIdx = i
                        break
                for a, b in pairwise(zeros):
                    print(1, a, b)
                print(1, zeros[-1], miIdx)
                print(2, miIdx)
                tmp = []
                for i in neg + pos:
                    if i == miIdx:
                        continue
                    tmp.append(i)
                for a, b in pairwise(tmp):
                    print(1, a, b)
    else:
        ans = 1
        pos = []
        neg = []
        for i in range(1, n + 1):
            if res[i] > 0:
                pos.append(i)
            else:
                neg.append(i)
                ans = -ans
        if ans > 0:
            for a, b in pairwise(neg + pos):
                print(1, a, b)
        else:
            mi = min(abs(res[i]) for i in neg)
            miIdx = -1
            for i in neg:
                if res[i] == -mi:
                    miIdx = i
                    break
            print(2, miIdx)
            tmp = []
            for i in range(1, n + 1):
                if i == miIdx:
                    continue
                tmp.append(i)
            for a, b in pairwise(tmp):
                print(1, a, b)


tt = 1
for ii in range(tt):
    # print(main())
    main()
