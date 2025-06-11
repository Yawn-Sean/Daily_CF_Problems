def main():
    n,m = map(int,input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        a,b = map(lambda x: int(x) - 1,input().split())
        g[a].append(b)
    ans = []
    vis = [0] * n
    def f(u):
        if vis[u]: return
        vis[u] = 1
        for v in g[u]:
            f(v)
        ans.append(u)
            
    for i in range(n):
        f(i)
    ans = [i + 1 for i in ans]
    print(*ans)


if __name__ == '__main__':
    main()

