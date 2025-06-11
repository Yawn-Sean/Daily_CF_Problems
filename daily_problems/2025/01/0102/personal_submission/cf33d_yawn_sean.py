# Submission link: https://codeforces.com/contest/33/submission/299305247
def main():
    n, m, q = MII()

    rs = [2 * 10 ** 9]
    xs = [0]
    ys = [0]

    for _ in range(n):
        r = 0
        x, y = MII()
        rs.append(r)
        xs.append(x)
        ys.append(y)

    for _ in range(m):
        r, x, y = MII()
        rs.append(r)
        xs.append(x)
        ys.append(y)

    st_range = sorted(range(n + m + 1), key=lambda x: -rs[x])

    nth_parent = [[-1] * (n + m + 1) for _ in range(13)]
    depth = [0] * (n + m + 1)

    for i in range(1, n + m + 1):
        for j in range(i - 1, -1, -1):
            u, v = st_range[i], st_range[j]
            if (xs[u] - xs[v]) ** 2 + (ys[u] - ys[v]) ** 2 < (rs[u] - rs[v]) ** 2:
                nth_parent[0][u] = v
                depth[u] = depth[v] + 1
                break

    for i in range(1, 13):
        for j in range(n + m + 1):
            if nth_parent[i - 1][j] != -1:
                nth_parent[i][j] = nth_parent[i - 1][nth_parent[i - 1][j]]

    def lca(u, v):
        if depth[u] > depth[v]:
            u, v = v, u
        
        x = depth[v] - depth[u]
        while x:
            bit = (x & -x).bit_length() - 1
            v = nth_parent[bit][v]
            x -= x & -x
        
        if u == v:
            return u
        
        for i in range(12, -1, -1):
            if nth_parent[i][u] != nth_parent[i][v]:
                u = nth_parent[i][u]
                v = nth_parent[i][v]
        return nth_parent[0][u]

    outs = []
    for _ in range(q):
        u, v = MII()
        outs.append(depth[u] + depth[v] - 2 * depth[lca(u, v)] - 2 if u != v else 0)

    print('\n'.join(map(str, outs)))