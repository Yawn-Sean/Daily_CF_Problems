def main():
    n, m = MII()
    edges = []
    for _ in range(m):
        u, v = GMI()
        edges.append((u, v))
    l, r = 1, m
    while l <= r:
        mid = (l + r) // 2
        path = [[] for _ in range(n)]
        ind = [0] * n
        for i in range(mid):
            u, v = edges[i]
            path[u].append(v)
            ind[v] += 1

        stack = [i for i in range(n) if ind[i] == 0]
        flag = True
        while stack:
            if len(stack) > 1:
                flag = False
                break
            u = stack.pop()
            for v in path[u]:
                ind[v] -= 1
                if ind[v] == 0:
                    stack.append(v)
        if flag:
            r = mid - 1
        else:
            l = mid + 1
    print(l if l <= m else -1)
    return


t = 1
for _ in range(t):
    main()
