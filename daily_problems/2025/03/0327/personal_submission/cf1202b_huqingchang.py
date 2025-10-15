def main():
    s = I()
    n = len(s)
    if n == 1:
        for _ in range(10):
            print(*[0] * 10)
        return

    def f(x, y):
        dp = []
        for start in range(10):
            dis = [0] * 10
            dq = deque([[start, 0]])
            while dq:
                a, d = dq.popleft()
                for ne in [(a + x) % 10, (a + y) % 10]:
                    if dis[ne] == 0:
                        dis[ne] = d + 1
                        dq.append([ne, d + 1])
            dp.append(dis)
        tmp = 0
        for ki, v in cnt.items():
            a, b = int(ki[0]), int(ki[1])
            if dp[a][b] == 0:
                return -1
            tmp += (dp[a][b] - 1) * v
        return tmp

    cnt = Counter()
    for a, b in pairwise(s):
        cnt[(a, b)] += 1
    ans = [[-1] * 10 for _ in range(10)]
    for i in range(10):
        for j in range(10):
            if i > j:
                ans[i][j] = ans[j][i]
            else:
                ans[i][j] = f(i, j)
    for r in ans:
        print(*r)


T = 1
for ii in range(T):
    # print(main())
    # print(ii)
    main()
