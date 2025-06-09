def main():
    cnt = LII()
    n = II()
    res = []
    s = ['S', 'M', 'L', 'XL', 'XXL', 'XXXL']
    d = dict(zip(s, list(range(6))))  # 根据尺码反查序号
    ans = [''] * n
    two = [[] for _ in range(6)]

    for i in range(n):
        cho = list(I().split(','))
        if len(cho) == 1:
            if not cnt[d[cho[0]]]:
                print('NO')
                return
            ans[i] = cho[0]
            cnt[d[cho[0]]] -= 1
        else:
            pre, aft = cho
            pre, aft = d[pre], d[aft]
            two[pre].append(i)
    for i in range(5):
        need = len(two[i])
        if cnt[i] + cnt[i + 1] < need:
            print('NO')
            return
        for candi in two[i]:
            if cnt[i]:
                ans[candi] = s[i]
                cnt[i] -= 1
            else:
                ans[candi] = s[i + 1]
                cnt[i + 1] -= 1
    print('YES')
    for an in ans:
        print(an)


T = 1
for ii in range(T):
    # print(main())
    # print(ii)
    main()
