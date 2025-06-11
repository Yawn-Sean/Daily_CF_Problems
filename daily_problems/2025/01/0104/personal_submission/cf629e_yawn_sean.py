# Submission link: https://codeforces.com/contest/704/submission/299535923
def main():
    n, q = MII()
    path = [[] for _ in range(n)]

    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    que = [0] * n
    l, r = 0, 1

    depth = [0] * n
    parent = [-1] * n

    while l < r:
        u = que[l]
        l += 1
        
        for v in path[u]:
            if parent[u] != v:
                depth[v] = depth[u] + 1
                parent[v] = u
                que[r] = v
                r += 1

    sz = [1] * n
    dp = [0] * n

    for i in range(n - 1, 0, -1):
        u = que[i]
        sz[parent[u]] += sz[u]
        dp[parent[u]] += dp[u] + sz[u]

    up_dp = [0] * n

    for i in range(1, n):
        u = que[i]
        up_dp[u] = up_dp[parent[u]] + n - sz[u] + (dp[parent[u]] - dp[u] - sz[u])

    nth_parent = [[-1] * n for _ in range(20)]
    for i in range(n):
        nth_parent[0][i] = parent[i]

    for i in range(19):
        for j in range(n):
            if nth_parent[i][j] != -1:
                nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]]

    def search(k, u):
        while k:
            bit = (k & -k).bit_length() - 1
            u = nth_parent[bit][u]
            k -= k & -k
        return u

    def lca(u, v):
        if depth[u] > depth[v]:
            u, v = v, u
        
        v = search(depth[v] - depth[u], v)
        if u == v: return u
        
        for i in range(19, -1, -1):
            if nth_parent[i][u] != nth_parent[i][v]:
                u = nth_parent[i][u]
                v = nth_parent[i][v]

        return nth_parent[0][u]

    for i in range(n):
        dp[i] /= sz[i]
        if i > 0: up_dp[i] /= n - sz[i]

    outs = []
    for _ in range(q):
        u, v = GMI()
        
        if depth[u] > depth[v]:
            u, v = v, u
        
        l = lca(u, v)
        d = depth[u] + depth[v] - 2 * depth[l]
        
        if l == u:
            tmp = search(d - 1, v)
            outs.append(d + up_dp[tmp] + dp[v])
        else:
            outs.append(d + 1 + dp[u] + dp[v])

    print('\n'.join(map(str, outs)))