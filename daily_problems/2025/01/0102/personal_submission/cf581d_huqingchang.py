def main():
    res = LII()
    mx = max(res)
    s = 0
    for i in range(3):
        s += res[i * 2] * res[i * 2 + 1]
    n = int(s ** 0.5)
    if n ** 2 != s:
        exit(print(-1))
    if mx != n:
        exit(print(-1))
    ans = [[''] * n for _ in range(n)]
    if res.count(n) == 3:
        for id in range(3):
            ch = ascii_uppercase[id]
            for i in range(n):
                if ans[i][0]:
                    continue
                for start in range(i, i + min(res[id * 2], res[id * 2 + 1])):
                    for j in range(n):
                        ans[start][j] = ch
                break
        print(n)
        for r in ans:
            print(''.join(r))
        return
    Idx = -1
    for i in range(3):
        if max(res[i * 2], res[i * 2 + 1]) == n:
            Idx = i
            break

    x = min(res[Idx * 2], res[Idx * 2 + 1])
    for i in range(n-x, n):
        for j in range(n):
            ans[i][j] = ascii_uppercase[Idx]
    restX = n - x
    cnt = 0
    for i in range(3):
        if i == Idx:
            continue
        if restX not in [res[i * 2], res[i * 2 + 1]]:
            exit(print(-1))
        cnt += 1
        restY = res[i * 2] + res[i * 2 + 1] - restX
        for l in range(restX):
            if cnt == 1:
                for k in range(restY):
                    ans[l][k] = ascii_uppercase[i]
            else:
                for k in range(n-restY, n):
                    ans[l][k] = ascii_uppercase[i]
    print(n)
    for r in ans:
        print(''.join(r))


T = 1
for ii in range(T):
    # print(main())
    main()
