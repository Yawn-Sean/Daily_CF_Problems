def main():
    n = int(input())
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u,v = map(lambda x: int(x) - 1,input().split())
        g[u].append(v)
        g[v].append(u)
    cnt = 0
    size = [1] * n
    color = [0] * n
    def dfs(u,f):
        nonlocal cnt
        cnt += color[u]
        for v in g[u]:
            if v != f:
                color[v] = 1 ^ color[u]
                dfs(v,u)
                size[u] += size[v]
    dfs(0,-1)
    ans = cnt * (n - cnt)
    for c in size:
        ans += c * (n - c)
    print(ans // 2)

main()