def main():
    n, k = MII()
    d = [0] + LII()
    edges = []
    deg = [0] * (n + 1)
    d_lis = defaultdict(list)
    mx_dis = 0
    for i in range(1, n + 1):
        d_lis[d[i]].append(i)
        mx_dis = fmax(mx_dis, d[i])
    if not d_lis[0] or len(d_lis[0]) > 1:
        exit(print(-1))

    for i in range(1, mx_dis + 1):
        if not d_lis[i]:
            exit(print(-1))
        pre = d_lis[i - 1][::]
        for node in d_lis[i]:
            while pre and deg[pre[-1]] == k:
                pre.pop()
            if not pre:
                exit(print(-1))
            edges.append([pre[-1], node])
            deg[pre[-1]] += 1
            deg[node] += 1
    print(len(edges))
    for a, b in edges:
        print(a, b)


T = 1
for ii in range(T):
    # print(main())
    # print(ii)
    main()
