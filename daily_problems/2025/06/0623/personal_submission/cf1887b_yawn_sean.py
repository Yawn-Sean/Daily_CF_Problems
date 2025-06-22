# Submission link: https://codeforces.com/contest/1887/submission/325625448
def main():
    n, t = MII()

    def f(i, u):
        return i * n + u

    path = [[] for _ in range(n)]

    for i in range(1, t + 1):
        m = II()
        
        for _ in range(m):
            u, v = GMI()
            path[u].append(f(i, v))
            path[v].append(f(i, u))

    k = II()
    times = LII()

    pos = [[] for _ in range(t + 1)]
    for i in range(k):
        pos[times[i]].append(i + 1)

    dis = [k + 1] * n
    dis[0] = 0

    pq = [f(0, 0)]

    while pq:
        d, u = divmod(heappop(pq), n)
        if dis[u] == d:
            for e_msk in path[u]:
                e_id, v = divmod(e_msk, n)
                p = bisect.bisect_left(pos[e_id], d + 1)
                if p < len(pos[e_id]):
                    nd = pos[e_id][p]
                    if nd < dis[v]:
                        dis[v] = nd
                        heappush(pq, f(nd, v))

    print(dis[n - 1] if dis[n - 1] <= k else -1)