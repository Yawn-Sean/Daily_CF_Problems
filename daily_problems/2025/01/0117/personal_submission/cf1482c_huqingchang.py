def main():
    n, m = MII()
    res = []
    ans = []
    for _ in range(m):
        res.append(LII()[1:])

    for r in res:
        ans.append(r[0])
    cnt = Counter(ans)
    mx = max(cnt.values())
    if mx <= (m + 1) // 2:
        print('YES')
        print(*ans)
        return
    for i, r in enumerate(res):
        if len(r) == 1:
            continue
        if cnt[r[0]] == mx:
            ans[i] = r[1]
            cnt[r[0]] -= 1
            mx -= 1
        if mx <= (m + 1) // 2:
            print('YES')
            print(*ans)
            return
    print('NO')


T = II()
for ii in range(T):
    # print(main())
    main()
