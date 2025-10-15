# Submission link: https://codeforces.com/contest/187/submission/309003825
def main():
    n, m, k = MII()
    pos = LII()

    ispos = [0] * (n + 1)
    for x in pos:
        ispos[x] = 1

    us = []
    vs = []

    path = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = MII()
        path[u].append(v)
        path[v].append(u)
        us.append(u)
        vs.append(v)

    s, t = MII()
    ispos[t] = 1

    que = [0] * (n + 1)
    froms = [-1] * (n + 1)
    dis = [n] * (n + 1)

    pl, pr = 0, 0
    for i in range(n + 1):
        if ispos[i]:
            dis[i] = 0
            froms[i] = i
            que[pr] = i
            pr += 1

    while pl < pr:
        u = que[pl]
        pl += 1
        
        for v in path[u]:
            if dis[v] == n:
                dis[v] = dis[u] + 1
                que[pr] = v
                pr += 1
                froms[v] = froms[u]

    tmp = [[] for _ in range(n)]
    for i in range(m):
        w = fmax(dis[us[i]], dis[vs[i]]) if froms[us[i]] == froms[vs[i]] else dis[us[i]] + dis[vs[i]] + 1
        if w < n:
            tmp[w].append(i)

    dsu = UnionFind(n + 1)
    for w in range(n):
        for i in tmp[w]:
            dsu.merge(us[i], vs[i])
            if dsu.find(s) == dsu.find(t):
                print(w)
                exit()

    print(-1)