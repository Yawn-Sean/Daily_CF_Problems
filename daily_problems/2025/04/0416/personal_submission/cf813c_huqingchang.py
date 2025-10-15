def main():
    n, x = MII()
    g = [[] for _ in range(n + 1)]
    layer = [0] * (n + 1)
    dis = [0] * (n + 1)
    pa = [-1] * (n + 1)
    deg_out = [0] * (n + 1)
    for _ in range(n - 1):
        u, v = MII()
        g[u].append(v)
        g[v].append(u)
    dq = deque([1])
    layer[1] = 1
    while dq:
        a = dq.popleft()
        for ne in g[a]:
            if not layer[ne]:
                layer[ne] = layer[a] + 1
                dq.append(ne)
                pa[ne] = a
                deg_out[a] += 1
    dq = deque()
    for i in range(1, n + 1):
        if not deg_out[i]:
            dq.append(i)
    while dq:
        a = dq.popleft()
        if a == 1:
            break
        dis[pa[a]] = fmax(dis[pa[a]], dis[a] + 1)
        deg_out[pa[a]] -= 1
        if deg_out[pa[a]] == 0:
            dq.append(pa[a])
    up = layer[x] - layer[1]
    up_step = (up - 1) // 2
    start = x
    for _ in range(up_step):
        start = pa[start]
    ans = 2 * (layer[start] - 1 + dis[start])
    return ans


T = 1
for ii in range(T):
    # print(ii)
    print(main())
