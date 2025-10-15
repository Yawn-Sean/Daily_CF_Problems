def main():
    n,m = map(int, input().split())
    p = list(map(lambda x : int(x) - 1, input().split()))
    g = [set() for _ in range(n)]
    
    for _ in range(m):
        u,v = map(lambda x : int(x) - 1, input().split())
        g[u].add(v)
    vis = [0 ] * n
    vis[p[-1]] = 1
    cnt = 1
    for i in range(n-2 , -1 , -1):
        v = 0
        for u in g[p[i]]:
            if vis[u]:
                v += 1
        if v < cnt:
            vis[p[i]] = 1
            cnt += 1
    print(n - cnt)

main()