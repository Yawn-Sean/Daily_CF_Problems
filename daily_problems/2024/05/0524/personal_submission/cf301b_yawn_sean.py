# Submission link: https://codeforces.com/contest/301/submission/262321974
def main():
    n, d = MII()
    nums = [0] + LII() + [0]
    xs = []
    ys = []

    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)

    dist = [-1] * n
    dist[0] = 0

    vis = [0] * n
    vis[0] = 1

    def f(u, v):
        return (abs(xs[u] - xs[v]) + abs(ys[u] - ys[v])) * d

    u = 0
    for _ in range(n - 1):
        v = -1
        for nv in range(n):
            if not vis[nv]:
                if dist[nv] == -1 or f(u, nv) - nums[nv] + dist[u] < dist[nv]:
                    dist[nv] = f(u, nv) - nums[nv] + dist[u]
                if v == -1 or dist[nv] < dist[v]:
                    v = nv
        vis[v] = 1
        u = v

    print(dist[-1])