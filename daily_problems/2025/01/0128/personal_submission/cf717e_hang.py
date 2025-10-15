# 过不去 翻译成cpp就好了 
# 应该是输入没优化的问题
def main():
    n = int(input())
    color = []
    for i in range(n):
        c = int(input())
        color.append(c)
    g = [[] for _ in range(n)]
    for i in range(n - 1):
        u, v = map(lambda x: int(x) - 1, input().split())
        g[u].append(v)
        g[v].append(u)
    if all(color[i] == 1 for i in range(n)):
        exit(print(1))
    
    path = []
    color[0] = -color[0]
    def opt(u):
        color[u] = -color[u]
        path.append(u)
    def dfs(u,f):
        opt(u)
        for v in g[u]:
            if v != f:
                dfs(v,u)
        if u != 0:
            if color[u] == 1:
                opt(f)
            else:
                opt(f)
                opt(u)
                opt(f)
        else:
            if color[u] == 1:
                pass
            else:
                v = g[u][0]
                opt(v)
                opt(u)
                opt(v)
    dfs(0,-1)
    path = [i + 1 for i in path]
    print(*path)
main()