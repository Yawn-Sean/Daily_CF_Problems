
# 跑最短路时记录是哪一条边更新这个点的
# 然后按 1 到每个点的最短路径升序排序，从前往后找记录的边就是保留的边
def main():
    n, m, k = map(int, input().split())

    us, vs, ws = [], [], []
    path = [[] for _ in range(n)]
    for i in range(m):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        us.append(u), vs.append(v), ws.append(w)
        path[u].append(i)
        path[v].append(i)

    dis = [10 ** 18 for _ in range(n)]
    dis[0] = 0
    Last = [-1 for _ in range(n)]
    pq = [0]

    while pq:
        d, u = divmod(heappop(pq), n)
        if dis[u] == d:
            for i in path[u]:
                v = us[i] ^ vs[i] ^ u
                if dis[v] > dis[u] + ws[i]:
                    dis[v] = dis[u] + ws[i]
                    Last[v] = i
                    heappush(pq, dis[v] * n + v)

    ps = sorted(range(1, n), key=lambda x: dis[x])
    k = min(k, n - 1)
    print(k)

    print(' '.join(str(Last[ps[i]] + 1) for i in range(k)))
