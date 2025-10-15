t = II()

for _ in range(t):
    k = II()
    n = k * 2
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v, w = MII()
        u -= 1
        v -= 1
        g[u].append((v, w))
        g[v].append((u, w))

    size = [0] * n
    fat = [-1] * n

    stack = [(0, -1)]
    visit_order = []
    while stack:
        node, parent = stack.pop()
        if size[node] == 0:
            size[node] = 1
            fat[node] = parent
            visit_order.append(node)
            for neighbor, _ in g[node]:
                if neighbor != parent:
                    stack.append((neighbor, node))

    for node in reversed(visit_order):
        parent = fat[node]
        if parent != -1:
            size[parent] += size[node]

    mi = mx = 0
    for i in range(n):
        for j, w in g[i]:
            if fat[j] == i:
                mi += (size[j] % 2) * w
                mx += fmin(size[j], n - size[j]) * w
            else:
                mi += (size[i] % 2) * w
                mx += fmin(size[i], n - size[i]) * w

    print(mi // 2, mx // 2)
