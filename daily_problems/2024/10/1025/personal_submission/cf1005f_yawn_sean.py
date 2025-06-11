# Submission link: https://codeforces.com/contest/1005/submission/287842009
def main():
    n, m, k = MII()

    us = []
    vs = []
    path = [[] for _ in range(n)]

    for i in range(m):
        u, v = GMI()
        us.append(u)
        vs.append(v)
        path[u].append(i)
        path[v].append(i)

    dis = [-1] * n
    dis[0] = 0

    dq = [0] * n
    l, r = 0, 1

    while l < r:
        u = dq[l]
        l += 1
        
        for i in path[u]:
            v = us[i] + vs[i] - u
            if dis[v] == -1:
                dis[v] = dis[u] + 1
                dq[r] = v
                r += 1

    pre_edges = [[] for _ in range(n)]

    cur = 1
    for u in range(1, n):
        for i in path[u]:
            v = us[i] + vs[i] - u
            if dis[u] == dis[v] + 1:
                pre_edges[u].append(i)
        cur = fmin(cur * len(pre_edges[u]), k)

    edge_mark = [0] * m
    outs = []

    for i in range(cur):
        for j in range(1, n):
            i, idx = divmod(i, len(pre_edges[j]))
            edge_mark[pre_edges[j][idx]] = 1
        outs.append(''.join(map(str, edge_mark)))
        for j in range(m):
            edge_mark[j] = 0

    print(cur)
    print('\n'.join(outs))