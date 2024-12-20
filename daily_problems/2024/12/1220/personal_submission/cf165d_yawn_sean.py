# Submission link: https://codeforces.com/contest/165/submission/297372057
def main():
    n = II()
    us = []
    vs = []

    path = [[] for _ in range(n)]
    for i in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
        us.append(u)
        vs.append(v)

    parent = [-1] * n
    depth = [0] * n
    ls = [-1] * n
    rs = [-1] * n

    stk = [0]
    tmstamp = 0

    while stk:
        u = stk.pop()
        if u >= 0:
            ls[u] = tmstamp
            tmstamp += 1
            stk.append(~u)
            for v in path[u]:
                if ls[v] == -1:
                    parent[v] = u
                    depth[v] = depth[u] + 1
                    stk.append(v)
        else:
            rs[~u] = tmstamp

    lca = LCA(parent, depth)
    fen = FenwickTree(n + 1)

    q = II()
    outs = []

    for _ in range(q):
        query = LII()
        if query[0] <= 2:
            eid = query[1] - 1
            u = us[eid] if depth[us[eid]] > depth[vs[eid]] else vs[eid]
            if query[0] == 1:
                fen.add(ls[u], -1)
                fen.add(rs[u], 1)
            else:
                fen.add(ls[u], 1)
                fen.add(rs[u], -1)
        else:
            u = query[1] - 1
            v = query[2] - 1
            l = lca.getLCA(u, v)
            outs.append(depth[u] + depth[v] - 2 * depth[l] if fen.rsum(0, ls[u]) + fen.rsum(0, ls[v]) - fen.rsum(0, ls[l]) * 2 == 0 else -1)

    print('\n'.join(map(str, outs)))