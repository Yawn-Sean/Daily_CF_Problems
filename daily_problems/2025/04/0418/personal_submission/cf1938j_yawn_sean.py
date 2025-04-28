# Submission link: https://codeforces.com/contest/1938/submission/316029991
def main():
    n, m = MII()
    path = [[] for _ in range(n)]

    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        
        path[u].append(w * n + v)
        path[v].append(w * n + u)

    parent = [-1] * n

    inf = 10 ** 9

    dis1 = [inf] * n
    dis1[0] = 0

    pq = [0]

    while pq:
        d, u = divmod(heappop(pq), n)
        if dis1[u] == d:
            for msk in path[u]:
                w, v = divmod(msk, n)
                if d + w < dis1[v]:
                    dis1[v] = d + w
                    parent[v] = u
                    heappush(pq, dis1[v] * n + v)

    vis = [0] * n
    cur = n - 1

    vis[cur] = 1

    while parent[cur] != -1:
        cur = parent[cur]
        vis[cur] = 1

    disn = [inf] * n
    disn[n - 1] = 0

    pq = [n - 1]

    while pq:
        d, u = divmod(heappop(pq), n)
        if disn[u] == d:
            for msk in path[u]:
                w, v = divmod(msk, n)
                if d + w < disn[v]:
                    disn[v] = d + w
                    parent[v] = u
                    heappush(pq, disn[v] * n + v)

    ans = inf

    for u in range(n):
        for msk in path[u]:
            w, v = divmod(msk, n)
            if vis[u] and vis[v] and (parent[u] == v or parent[v] == u):
                continue
            ans = fmin(ans, dis1[u] + disn[v] + w)

    print(ans + dis1[n - 1] if ans < inf else -1)