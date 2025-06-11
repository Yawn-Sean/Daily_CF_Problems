def main():
    n, k = MII()
    res = LII()
    vis = [-1] * 256
    ln = [0] * 256
    for x in res:
        if vis[x] != -1:
            continue
        pre = -1
        for i in range(k):
            pre = x - i
            if pre < 0:
                pre += 1
                break
            if vis[pre] != -1:
                if ln[vis[pre]] + x - pre <= k:
                    for j in range(x, pre, -1):
                        vis[j] = vis[pre]
                        ln[vis[pre]] += 1
                    break
                else:
                    for j in range(x, pre, -1):
                        vis[j] = pre + 1
                        ln[pre + 1] += 1
                    break
        if vis[x] == -1:
            for j in range(pre, x + 1):
                vis[j] = pre
                ln[pre] += 1
    ans = []
    for x in res:
        ans.append(vis[x])
    print(*ans)


T = 1
for ii in range(T):
    # print(main())
    # print(ii)
    main()
