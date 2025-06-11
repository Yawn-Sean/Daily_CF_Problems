# Submission link: https://codeforces.com/problemset/submission/685/318389837
def main():
    n, q = MII()
    parent = [-1] + LGMI()

    path = [[] for _ in range(n)]

    for i in range(1, n):
        path[parent[i]].append(i)

    que = [0]
    for u in que:
        for v in path[u]:
            que.append(v)

    sz = [1] * n

    for i in range(n - 1, 0, -1):
        u = que[i]
        p = parent[u]
        sz[p] += sz[u]

    centroid = [-1] * n

    for i in range(n - 1, -1, -1):
        u = que[i]
        if len(path[u]) == 0:
            centroid[u] = u
        else:
            v = -1
            for nv in path[u]:
                if v == -1 or sz[nv] > sz[v]:
                    v = nv
            v = centroid[v]
            while 2 * sz[v] < sz[u]:
                v = parent[v]
            centroid[u] = v

    outs = []
    for _ in range(q):
        outs.append(centroid[II() - 1] + 1)

    print('\n'.join(map(str, outs)))