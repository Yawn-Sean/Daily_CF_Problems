def main():
    n,m,h,t = map(int,input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        u,v = map(lambda x:int(x) - 1,input().split())
        g[u].append(v)
        g[v].append(u)
    used = [0] * n
    def f(u,v):
        if len(g[u])  <= h or len(g[v]) <= t:
            return
        used[u] = -1
        used[v] = -1
        cnt = 0
        for w in g[u]:
            if used[w] == 0:
                cnt += 1
            used[w] |= 1
        for w in g[v]:
            if used[w] == 0:
                cnt += 1
            used[w] |= 2
        if cnt >= h + t:
            h1 = [w for w in g[u] if used[w] == 1]
            v1 = [w for w in g[v] if used[w] == 2]
            hv = [w for w in g[u] if used[w] == 3]
            r1 = h1[:h]
            r2 = v1[:t]
            for w in hv:
                if len(r1) < h:
                    r1.append(w)
                elif len(r2) < t:
                    r2.append(w)
            print('YES')
            print(u+1,v + 1)
            r1 = [w + 1 for w in r1]
            r2 = [w + 1 for w in r2]
            print(*r1)
            print(*r2)
            exit()
        for w in g[u]:
            used[w] = 0
        for w in g[v]:
            used[w] = 0


    for u in range(n):
        for v in g[u]:
            f(u,v)
    print('NO')
main()