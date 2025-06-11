def main():
    n,x,y = map(int,input().split())
    x,y = x-1,y-1
    g = [[] for _ in range(n)]
    for _ in range(n-1):
        a,b = map(lambda x:int(x) -1 ,input().split())
        g[a].append(b)
        g[b].append(a)
    fa = [-1] * n
    order = []
    def f(u):
        order.append(u)
        for v in g[u]:
            if fa[u] != v:
                fa[v] = u
                f(v)
    f(x)
    sz = [1] * n
    for u in reversed(order):
        if fa[u] != -1:
            sz[fa[u]] += sz[u]
    a = sz[y]
    while fa[y] != x:
        y = fa[y]
    b = n - sz[y]
    print(n * (n - 1) - a * b)
main()