def main():
    n = II()
    res = LII()
    mx = max(res)
    ops = []

    while 1:
        mi = min(res)
        if mx == mi:
            break
        cnt = Counter(res)
        if cnt[mx] > 1:
            candi = deque()
            for i in range(n):
                if res[i] == mx:
                    candi.append(i)
                    res[i] -= 1
            while candi:
                tmp = ['0'] * n
                if len(candi) & 1:
                    for _ in range(3):
                        a = candi.popleft()
                        tmp[a] = '1'
                else:
                    for _ in range(2):
                        a = candi.popleft()
                        tmp[a] = '1'
                ops.append(''.join(tmp))
            mx -= 1
        else:
            secMx = 0
            fir, sec = -1, -1
            for i in range(n):
                if res[i] < mx:
                    secMx = max(secMx, res[i])
                elif res[i] == mx:
                    fir = i
            for i in range(n):
                if res[i] == secMx:
                    sec = i
                    break
            tmp = ['0'] * n
            tmp[fir] = tmp[sec] = '1'
            if res[sec]:
                res[sec] -= 1
            res[fir] -= 1
            mx -= 1
            ops.append(''.join(tmp))
    print(mx)
    print(len(ops))
    for s in ops:
        print(s)


T = 1
for ii in range(T):
    # print(main())
    main()
