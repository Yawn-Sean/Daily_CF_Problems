# Submission link: https://codeforces.com/contest/832/submission/274610113
def main():
    n, q = MII()
    parent = [-1] + LGMI()

    path = [[] for _ in range(n)]
    for i in range(1, n):
        path[parent[i]].append(i)

    order = []
    depth = [0] * n
    stk = [0]
    while stk:
        u = stk.pop()
        order.append(u)
        for v in path[u]:
            depth[v] = depth[u] + 1
            stk.append(v)

    size = [1] * n
    for i in reversed(order):
        if parent[i] != -1:
            size[parent[i]] += size[i]

    chains = list(range(n))
    for i in order:
        mx = -1
        for j in path[i]:
            if mx == -1 or size[j] > size[mx]:
                mx = j
        if mx != -1:
            chains[mx] = chains[i]

    def lca(u, v):
        while chains[u] != chains[v]:
            if depth[chains[u]] < depth[chains[v]]:
                v = parent[chains[v]]
            else:
                u = parent[chains[u]]
        return u if depth[u] < depth[v] else v

    def dis(u, v):
        return depth[u] + depth[v] - 2 * depth[lca(u, v)]

    outs = []
    for _ in range(q):
        a, b, c = GMI()
        d1, d2, d3 = dis(a, b), dis(b, c), dis(c, a)
        outs.append((d1 + d2 + d3 - min(d1, d2, d3) * 2) // 2 + 1)

    print(*outs, sep='\n')