# Submission link: https://codeforces.com/contest/1092/submission/276332650
def main():
    n, m = MII()
    path = [[] for _ in range(n)]

    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    diameters = [[] for _ in range(n)]
    q = [0] * n
    d = [-n-1] * n
    parent = [-1] * n

    for i in range(n):
        if d[i] == -n-1:
            l, r = 0, 1
            q[l] = i
            d[i] = -1
            while l < r:
                u = q[l]
                l += 1
                for v in path[u]:
                    if d[v] == -n-1:
                        d[v] = d[u] - 1
                        q[r] = v
                        r += 1
            
            l, r = 0, 1
            q[l] = u
            d[u] = 0
            while l < r:
                u = q[l]
                l += 1
                for v in path[u]:
                    if d[v] < 0:
                        d[v] = d[u] + 1
                        parent[v] = u
                        q[r] = v
                        r += 1
            
            dis = d[u]
            for _ in range(dis // 2):
                u = parent[u]
            diameters[dis].append(u)

    outs = []
    cur, ma = -1, 0
    for i in range(n - 1, -1, -1):
        for u in diameters[i]:
            if cur == -1:
                cur = u
                ma = i
            else:
                outs.append(f'{cur + 1} {u + 1}')
                ma = fmax(ma, ((i + 1) // 2 + (ma + 1) // 2 + 1))

    print(ma)
    print('\n'.join(outs))