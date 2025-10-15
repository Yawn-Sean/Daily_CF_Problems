def main():
    n = II()
    g = [[] for i in range(n)]
    ed = [defaultdict(int) for i in range(n)]
    for i in range(n - 1):
        u,v = GMI()
        g[u].append(v)
        g[v].append(u)
        ed[u][v] = i + 1
        ed[v][u] = i + 1

    stk = [[0,-1]]
    parent = [-1] * n
    ans = defaultdict(list)
    while stk:
        u,col = stk.pop()
        k = 1
        for v in g[u]:
            if parent[u] != v:
                parent[v] = u
                while k == col:
                    k += 1
                stk.append([v,k])
                ans[k].append(ed[u][v])
                k += 1
    print(len(ans))
    for k,v in ans.items():
        print(len(v),*v)

